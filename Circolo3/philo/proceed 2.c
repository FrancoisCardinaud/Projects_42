/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed 2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:19:34 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philosopher *philo)
{
	t_info	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork_nbr]));
	print_action(data, philo->nbr, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork_nbr]));
	print_action(data, philo->nbr, "has taken a fork");
	pthread_mutex_lock(&(data->meal_check));
	print_action(data, philo->nbr, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(data->meal_check));
	smart_sleep(data->time_eat, data);
	(philo->philo_ate)++;
	pthread_mutex_unlock(&(data->forks[philo->left_fork_nbr]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork_nbr]));
}

void	*p_thread(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_info			*data;

	i = 0;
	philo = (t_philosopher *)void_philosopher;
	data = philo->data;
	if (philo->nbr % 2)
		usleep(15000);
	while (!(data->died))
	{
		eat(philo);
		if (data->all_ate)
			break ;
		print_action(data, philo->nbr, "is sleeping");
		smart_sleep(data->time_sleep, data);
		print_action(data, philo->nbr, "is thinking");
		i++;
	}
	return (NULL);
}

void	quit_proceed(t_info *data, t_philosopher *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_nbr)
		pthread_join(philos[i].thread_nbr, NULL);
	i = -1;
	while (++i < data->philo_nbr)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->writing));
}

void	death_checker(t_info *r, t_philosopher *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->philo_nbr && !(r->died))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_delta(p[i].last_meal, get_time()) > r->time_death)
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
		while (r->meals != -1 && i < r->philo_nbr && p[i].philo_ate >= r->meals)
			i++;
		if (i == r->philo_nbr)
			r->all_ate = 1;
	}
}

int	proceed(t_info *data)
{
	int				i;
	t_philosopher	*phi;

	i = 0;
	phi = data->philosophers;
	data->first_time = get_time();
	while (i < data->philo_nbr)
	{
		if (pthread_create(&(phi[i].thread_nbr), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].last_meal = get_time();
		i++;
	}
	death_checker(data, data->philosophers);
	quit_proceed(data, phi);
	return (0);
}
