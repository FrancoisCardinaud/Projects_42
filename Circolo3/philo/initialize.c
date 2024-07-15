/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:47:47 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_mutex(t_info *data)
{
	int	i;

	i = data->philo_nbr;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(data->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL))
		return (1);
	return (0);
}

int	initialize_philosophers(t_info *data)
{
	int	i;

	i = data->philo_nbr;
	while (--i >= 0)
	{
		data->philosophers[i].nbr = i;
		data->philosophers[i].philo_ate = 0;
		data->philosophers[i].left_fork_nbr = i;
		data->philosophers[i].right_fork_nbr = (i + 1) % data->philo_nbr;
		data->philosophers[i].last_meal = 0;
		data->philosophers[i].data = data;
	}
	return (0);
}

int	initialize(t_info *data, char **argv)
{
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_death = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->all_ate = 0;
	data->died = 0;
	if (data->philo_nbr < 1 || data->time_death < 0 || data->time_eat < 0
		|| data->time_sleep < 0 || data->philo_nbr > 250)
		return (1);
	if (argv[5])
	{
		data->meals = ft_atoi(argv[5]);
		if (data->meals <= 0)
			return (1);
	}
	else
		data->meals = -1;
	if (initialize_mutex(data))
		return (2);
	initialize_philosophers(data);
	return (0);
}
