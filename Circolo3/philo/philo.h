/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:30:58 by gsmets            #+#    #+#             */
/*   Updated: 2023/05/31 15:53:08 by fcardina         ###   ########.fr       */
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
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		t_last_meal;
	struct s_data	*data;
	pthread_t		thread_id;
}					t_philosopher;

typedef struct s_data
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
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
int					init(t_data *data, char **argv);
int					launcher(t_data *data);
void				print_action(t_data *data, int id, char *string);
void				quit_launcher(t_data *data, t_philosopher *philos);
void				smart_sleep(long long time, t_data *data);
long long			time_delta(long long past, long long pres);

#endif
