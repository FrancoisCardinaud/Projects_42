/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:47:47 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/31 15:30:25 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_sem(t_data *data)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
	data->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, data->nb_philo);
	data->writing = sem_open("/philo_write", O_CREAT, S_IRWXU, 1);
	data->meal_check = sem_open("/philo_mealcheck", O_CREAT, S_IRWXU, 1);
	if (data->forks <= 0 || data->writing <= 0 || data->meal_check <= 0)
		return (1);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].x_ate = 0;
		data->philosophers[i].t_last_meal = 0;
		data->philosophers[i].data = data;
	}
	return (0);
}

int	init(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_death = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->died = 0;
	if (data->nb_philo < 1 || data->time_death < 0 || data->time_eat < 0
		|| data->time_sleep < 0 || data->nb_philo > 250)
		return (1);
	if (argv[5])
	{
		data->nb_eat = ft_atoi(argv[5]);
		if (data->nb_eat <= 0)
			return (1);
	}
	else
		data->nb_eat = -1;
	if (data->nb_eat == 1)
		data->nb_eat++;
	if (init_sem(data))
		return (2);
	init_philo(data);
	return (0);
}
