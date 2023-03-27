/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:06:12 by francoiscar       #+#    #+#             */
/*   Updated: 2023/03/27 01:58:59 by fcardina         ###   ########.fr       */
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

void	sigur1_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_global.top_bit)
	{
		g_global.top_bit = 1 << 6;
		++(g_global.top_byte);
	}
	g_global.message[g_global.top_byte] += g_global.top_bit;
	g_global.top_bit >>= 1;
	if (g_global.top_byte == G_BUFFSIZE - 2 && !g_global.top_bit)
		g_global.buff_overflow = TRUE;
}

void	sigur2_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_global.top_bit)
	{
		g_global.top_bit = 1 << 6;
		++(g_global.top_byte);
	}
	g_global.top_bit >>= 1;
	if (g_global.top_byte == G_BUFFSIZE - 2 && !g_global.top_bit)
		g_global.buff_overflow = TRUE;
	else if (!g_global.message[g_global.top_byte]
		&& !g_global.top_bit)
	{
		g_global.all_receive = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool	server(void)
{
	while (1)
	{
		pause();
		if (g_global.all_receive || g_global.buff_overflow)
		{
			write(1, g_global.message, ft_strlen(g_global.message));
			ft_bzero(g_global.message, G_BUFFSIZE);
			g_global.top_byte = 0;
			g_global.top_bit = 1 << 6;
			if (g_global.all_receive)
				write(1, "\n", 1);
			g_global.all_receive = FALSE;
			g_global.buff_overflow = FALSE;
		}
	}
	return (TRUE);
}

int	main(void)
{
	struct sigaction	sigur1_act;
	struct sigaction	sigur2_act;

	sigur1_act.sa_sigaction = sigur1_bit;
	sigur2_act.sa_sigaction = sigur2_bit;
	sigur1_act.sa_flags = SA_SIGINFO;
	sigur2_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sigur1_act, NULL) != 0)
	{
		write(2, "Signal error\n", ft_strlen("Signal error\n"));
		exit(1);
	}
	if (sigaction(SIGUSR2, &sigur2_act, NULL) != 0)
	{
		write(2, "Signal error\n", ft_strlen("Signal error\n"));
		exit(1);
	}
	print_pid();
	ft_bzero(g_global.message, G_BUFFSIZE);
	server();
}
