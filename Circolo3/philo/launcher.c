/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:19:34 by gsmets            #+#    #+#             */
/*   Updated: 2023/05/31 15:30:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork_id]));
	print_action(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork_id]));
	print_action(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->meal_check));
	print_action(data, philo->id, "is eating");
	philo->t_last_meal = get_time();
	pthread_mutex_unlock(&(data->meal_check));
	smart_sleep(data->time_eat, data);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(data->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork_id]));
}

void	*p_thread(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_data			*data;

	i = 0;
	philo = (t_philosopher *)void_philosopher;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (!(data->died))
	{
		eat(philo);
		if (data->all_ate)
			break ;
		print_action(data, philo->id, "is sleeping");
		smart_sleep(data->time_sleep, data);
		print_action(data, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	quit_launcher(t_data *data, t_philosopher *philos)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->writing));
}

void	death_checker(t_data *r, t_philosopher *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->died))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_delta(p[i].t_last_meal, get_time()) > r->time_death)
			{
				print_action(r, i, "died");
				r->died = 1;
				exit(1);
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->died)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

int	launcher(t_data *data)
{
	int				i;
	t_philosopher	*phi;

	i = 0;
	phi = data->philosophers;
	data->first_time = get_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].t_last_meal = get_time();
		i++;
	}
	death_checker(data, data->philosophers);
	quit_launcher(data, phi);
	return (0);
}
