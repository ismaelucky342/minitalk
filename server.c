
#include <signal.h>
#include <zconf.h>
#include "minitalk.h"
#include "libft/libft.h"

void		print_pid(void)
{
	char	*tmp_pid;

	tmp_pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, tmp_pid, ft_strlen(tmp_pid));
	write(1, "\n", 1);
	free(tmp_pid);
}

void		activebit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!gprint.top_bit)
	{
		gprint.top_bit = 1 << 6;
		++(gprint.top_byte);
	}
	gprint.message[g_to_print.top_byte] += gprint.top_bit;
	gprint.top_bit >>= 1;
	if (g_to_print.top_byte == BUFFERSIZE - 2 && !gprint.top_bit)
		gprint.buff_overflow = TRUE;
}

void		nullbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!gprint.top_bit)
	{
		gprint.top_bit = 1 << 6;
		++(gprint.top_byte);
	}
	gprint.top_bit >>= 1;
	if (gprint.top_byte == BUFFERSIZE - 2 && !gprint.top_bit)
		gprint.buff_overflow = TRUE;
	else if (!gprint.message[gprint.top_byte]
		&& !gprint.top_bit)
	{
		gprint.all_receive = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool		main_handler(void)
{
	while (1)
	{
		pause();
		if (gprint.all_receive || gprint.buff_overflow)
		{
			write(1, gprint.message, ft_strlen(gprint.message));
			ft_bzero(gprint.message, BUFFERSIZE);
			gprint.top_byte = 0;
			gprint.top_bit = 1 << 6;
			if (gprint.all_receive)
				write(1, "\n", 1);
			gprint.all_receive = FALSE;
			gprint.buff_overflow = FALSE;
		}
	}
	return (TRUE);
}

int			main(void)
{
	struct sigaction active_act;
	struct sigaction null_act;

	active_act.sa_sigaction = activebit;
	null_act.sa_sigaction = nullbit;
	active_act.sa_flags = SA_SIGINFO;
	null_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0)
		error("signal error\n");
	if (sigaction(SIGUSR2, &null_act, NULL) != 0)
		error("signal error\n");
	print_pid();
	ft_bzero(gprint.message, BUFFSIZE);
	main_handler();
}