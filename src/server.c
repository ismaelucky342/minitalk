/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:52 by ismherna          #+#    #+#             */
/*   Updated: 2024/06/18 03:25:00 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	ft_confirm(int sig, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %u\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_confirm;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

static void	ft_confirm(int sig, siginfo_t *info, void *context)
{
	static char	bits[9] = {0};
	static int	bitcount = 0;
	char		c;

	(void)context;
	if (sig == SIGUSR2)
		bits[bitcount] = '0';
	else if (sig == SIGUSR1)
		bits[bitcount] = '1';
	bitcount++;
	if (bitcount == 8)
	{
		bits[8] = '\0';
		c = (char)strtol(bits, NULL, 2);
		ft_printf("%c", c);
		bitcount = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
