/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:05:39 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/02/21 23:05:46 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include "libft.h"
#include "minitalk.h"

/*
** Parameters: ./client [server-pid] [message]
*/

void	howto(void)
{
	write(1, "How to use: ./client [server-pid] [message]\n", 39);
	exit(0);
}

void	send_char(int pid, unsigned char byte)
{
	uint8_t		counter;

	counter = 1 << 6;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("bad pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("bad pid\n");
		}
		counter >>= 1;
		usleep(600);
	}
}

void	main_handler(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		++message;
	}
	send_char(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Data has been received.\n", 25);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		howto();
	signal(SIGUSR1, success);
	main_handler(argv[1], argv[2]);
	return (0);
}
