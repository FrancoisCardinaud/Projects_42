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

void	howto(void)
{
	write(1, "How to use: ./client [Server PID] \"Message\"\n", 44);
	exit(0);
}

void	send_byte(int pid, unsigned char byte)
{
	uint8_t		i;

	i = 1 << 6;
	while (i)
	{
		if (byte & i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Wrong PID\n", ft_strlen("Wrong PID\n"));
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Wrong PID\n", ft_strlen("Wrong PID\n"));
				exit(1);
			}
		}
		i >>= 1;
		usleep(600);
	}
}

void	client(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_byte(pid, *message);
		message++;
	}
	send_byte(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Data was received.\n", 19);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isnbr(argv[1]))
		howto();
	signal(SIGUSR1, success);
	client(argv[1], argv[2]);
	return (0);
}
