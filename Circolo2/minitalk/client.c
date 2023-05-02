/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:05:39 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/02 16:16:56 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <zconf.h>

void	howto(void)
{
	write(1, "How to use: ./client [Server PID] \"Message\"\n", 44);
	exit(0);
}

void	send_msg(int pid, char *msg)
{
	int		i;
	int		t;
	char	c;

	while (*msg)
	{
		i = 8;
		c = *msg++;
		while (i--)
		{
			if (c >> i & 1)
				t = kill(pid, SIGUSR2);
			else
				t = kill(pid, SIGUSR1);
			usleep(100);
			if (t == -1)
				exit(1);
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
	static int	rec;

	rec = 0;
	if (sig == SIGUSR1)
		++rec;
	else
	{
		return ;
	}
	(void)sig;
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isnbr(argv[1]))
		howto();
	signal(SIGUSR1, client);
	signal(SIGUSR2, client);
	send_msg(ft_atoi(argv[1]), argv[2]);
	write(1, "Data was received.\n", 19);
	return (0);
}
