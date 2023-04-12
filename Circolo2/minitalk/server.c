/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:06:12 by francoiscar       #+#    #+#             */
/*   Updated: 2023/04/12 16:44:18 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include "minitalk.h"
#include "libft.h"

void	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

void	server(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			write(1, "\n", 1);
			return;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sigur_action;

	print_pid();
	sigur_action.sa_sigaction = server;
	sigur_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sigur_action, NULL) != 0)
	{
		write(2, "Signal error\n", ft_strlen("Signal error\n"));
		exit(1);
	}
	if (sigaction(SIGUSR2, &sigur_action, NULL) != 0)
	{
		write(2, "Signal error\n", ft_strlen("Signal error\n"));
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
