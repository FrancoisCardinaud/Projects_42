/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:19:34 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/27 18:09:35 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philosopher *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	sem_wait(rules->forks);
	print_action(rules, philo->id, "has taken a fork");
	sem_wait(rules->forks);
	print_action(rules, philo->id, "has taken a fork");
	sem_wait(rules->meal_check);
	print_action(rules, philo->id, "is eating");
	philo->t_last_meal = get_time();
	sem_post(rules->meal_check);
	smart_sleep(rules->time_eat, rules);
	(philo->x_ate)++;
	sem_post(rules->forks);
	sem_post(rules->forks);
}

void	*death_check(void *void_philosopher)
{
	t_philosopher	*philo;
	t_rules			*r;

	philo = (t_philosopher *)void_philosopher;
	r = philo->rules;
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
	t_rules			*rules;

	philo = (t_philosopher *)void_phil;
	rules = philo->rules;
	philo->t_last_meal = get_time();
	pthread_create(&(philo->death_check), NULL, death_check, void_phil);
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->died))
	{
		eat(philo);
		if (philo->x_ate >= rules->nb_eat && rules->nb_eat != -1)
			break ;
		print_action(rules, philo->id, "is sleeping");
		smart_sleep(rules->time_sleep, rules);
		print_action(rules, philo->id, "is thinking");
	}
	pthread_join(philo->death_check, NULL);
	if (rules->died)
		exit(1);
	exit(0);
}

void	quit_launcher(t_rules *rules)
{
	int	i;
	int	ret;

	i = 0;
	while (i < rules->nb_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < rules->nb_philo)
				kill(rules->philosophers[i].proc_id, 15);
			break ;
		}
		i++;
	}
	sem_close(rules->forks);
	sem_close(rules->writing);
	sem_close(rules->meal_check);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
}

int	launcher(t_rules *rules)
{
	int				i;
	t_philosopher	*phi;

	i = -1;
	phi = rules->philosophers;
	rules->first_time = get_time();
	while (++i < rules->nb_philo)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			p_process(&(phi[i]));
		usleep(100);
	}
	quit_launcher(rules);
	return (0);
}
