/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:30:57 by ismherna          #+#    #+#             */
/*   Updated: 2024/06/18 03:22:48 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t	g_acknowledged = 0;

static void	ft_acknowledge(int sig)
{
	(void)sig;
	g_acknowledged = 1;
}

static void	ft_send_msg(int pid, char *s)
{
	size_t	i;

	signal(SIGUSR1, ft_acknowledge);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		while (!g_acknowledged)
			pause();
		g_acknowledged = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_string2bin(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("allocation went wrong\n");
		return (0);
	}
	ft_send_msg(pid, bits);
	free(bits);
	return (0);
}
