/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:06:12 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/02/21 23:06:16 by francoiscardi    ###   ########.fr       */
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
	if (!global.top_bit)
	{
		global.top_bit = 1 << 6;
		++(global.top_byte);
	}
	global.message[global.top_byte] += global.top_bit;
	global.top_bit >>= 1;
	if (global.top_byte == G_BUFFSIZE - 2 && !global.top_bit)
		global.buff_overflow = TRUE;
}

void	sigur2_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!global.top_bit)
	{
		global.top_bit = 1 << 6;
		++(global.top_byte);
	}
	global.top_bit >>= 1;
	if (global.top_byte == G_BUFFSIZE - 2 && !global.top_bit)
		global.buff_overflow = TRUE;
	else if (!global.message[global.top_byte]
		&& !global.top_bit)
	{
		global.all_receive = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool	server(void)
{
	while (1)
	{
		pause();
		if (global.all_receive || global.buff_overflow)
		{
			write(1, global.message, ft_strlen(global.message));
			ft_bzero(global.message, G_BUFFSIZE);
			global.top_byte = 0;
			global.top_bit = 1 << 6;
			if (global.all_receive)
				write(1, "\n", 1);
			global.all_receive = FALSE;
			global.buff_overflow = FALSE;
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
	ft_bzero(global.message, G_BUFFSIZE);
	server();
}
