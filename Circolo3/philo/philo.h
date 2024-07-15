/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:57:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
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
}					t_info;

int					ft_atoi(const char *str);
long long			get_time(void);
int					initialize(t_info *data, char **argv);
int					proceed(t_info *data);
void				print_action(t_info *data, int nbr, char *string);
void				quit_proceed(t_info *data, t_philosopher *philos);
void				smart_sleep(long long time, t_info *data);
long long			time_delta(long long past, long long pres);

#endif
