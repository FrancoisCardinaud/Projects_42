/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:19:34 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/31 15:30:25 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	print_action(data, philo->id, "has taken a fork");
	sem_wait(data->forks);
	print_action(data, philo->id, "has taken a fork");
	sem_wait(data->meal_check);
	print_action(data, philo->id, "is eating");
	philo->t_last_meal = get_time();
	sem_post(data->meal_check);
	smart_sleep(data->time_eat, data);
	(philo->x_ate)++;
	sem_post(data->forks);
	sem_post(data->forks);
}

void	*death_check(void *void_philosopher)
{
	t_philosopher	*philo;
	t_data			*r;

	philo = (t_philosopher *)void_philosopher;
	r = philo->data;
	while (42)
	{
		sem_wait(r->meal_check);
		if (time_delta(philo->t_last_meal, get_time()) > r->time_death)
		{
			print_action(r, philo->id, "died");
			r->died = 1;
			sem_wait(r->writing);
			exit(1);
		}
		sem_post(r->meal_check);
		if (r->died)
			break ;
		usleep(1000);
		if (philo->x_ate >= r->nb_eat && r->nb_eat != -1)
			break ;
	}
	return (NULL);
}

void	p_process(void *void_phil)
{
	t_philosopher	*philo;
	t_data			*data;

	philo = (t_philosopher *)void_phil;
	data = philo->data;
	philo->t_last_meal = get_time();
	pthread_create(&(philo->death_check), NULL, death_check, void_phil);
	if (philo->id % 2)
		usleep(15000);
	while (!(data->died))
	{
		eat(philo);
		if (philo->x_ate >= data->nb_eat && data->nb_eat != -1)
			break ;
		print_action(data, philo->id, "is sleeping");
		smart_sleep(data->time_sleep, data);
		print_action(data, philo->id, "is thinking");
	}
	pthread_join(philo->death_check, NULL);
	if (data->died)
		exit(1);
	exit(0);
}

void	quit_launcher(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < data->nb_philo)
				kill(data->philosophers[i].proc_id, 15);
			break ;
		}
		i++;
	}
	sem_close(data->forks);
	sem_close(data->writing);
	sem_close(data->meal_check);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
}

int	launcher(t_data *data)
{
	int				i;
	t_philosopher	*phi;

	i = -1;
	phi = data->philosophers;
	data->first_time = get_time();
	while (++i < data->nb_philo)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			p_process(&(phi[i]));
		usleep(100);
	}
	quit_launcher(data);
	return (0);
}
