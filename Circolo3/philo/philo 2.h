/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:57:54 by fcardina          #+#    #+#             */
/*   Updated: 2023/06/07 17:04:08 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct	s_data;

typedef struct s_philosopher
{
	int				nbr;
	int				philo_ate;
	int				left_fork_nbr;
	int				right_fork_nbr;
	long long		last_meal;
	struct s_data	*data;
	pthread_t		thread_nbr;
}					t_philosopher;

typedef struct s_data
{
	int				philo_nbr;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				meals;
	int				died;
	int				all_ate;
	long long		first_time;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	writing;
	t_philosopher	philosophers[250];
}					t_data;

int					ft_atoi(const char *str);
long long			get_time(void);
int					initialize(t_data *data, char **argv);
int					proceed(t_data *data);
void				print_action(t_data *data, int nbr, char *string);
void				quit_proceed(t_data *data, t_philosopher *philos);
void				smart_sleep(long long time, t_data *data);
long long			time_delta(long long past, long long pres);

#endif
