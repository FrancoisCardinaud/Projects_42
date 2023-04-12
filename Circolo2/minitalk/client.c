/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:05:39 by francoiscar       #+#    #+#             */
/*   Updated: 2023/04/12 15:53:23 by fcardina         ###   ########.fr       */
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

void	send_msg(int pid, char *msg)
{
	int		i;
	char	c;

	while (*msg)
	{
		i = 8;
		c = *msg++;
		while(i--)
		{
			if (c >> i & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					write(2, "Wrong PID\n", ft_strlen("Wrong PID\n"));
					exit(1);
				}
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					write(2, "Wrong PID\n", ft_strlen("Wrong PID\n"));
					exit(1);
				}
			}
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

static void	client(int sig)
{
	static int	rec = 0;

	if (sig == SIGUSR1)
		++rec;
	else
	{
		ft_putnbr_fd(rec, 1);
		ft_putchar_fd('\n', 1);
		return ;
	}
	(void)sig;
	write(1, "Data was received.\n", 19);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isnbr(argv[1]))
		howto();
	signal(SIGUSR1, client);
	signal(SIGUSR2, client);
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
