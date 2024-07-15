/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils 2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:59:07 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		value *= 10;
		value += *s - 48;
		s++;
	}
	return (value * sign);
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_delta(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_info *data)
{
	long long	i;

	i = get_time();
	while (!(data->died))
	{
		if (time_delta(i, get_time()) >= time)
			break ;
		usleep(50);
	}
}

void	print_action(t_info *data, int nbr, char *string)
{
	pthread_mutex_lock(&(data->writing));
	if (!(data->died))
	{
		printf("%lli ", get_time() - data->first_time);
		printf("%i ", nbr + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(data->writing));
	return ;
}
