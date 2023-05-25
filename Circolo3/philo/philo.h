/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:30:58 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:04 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

struct	s_rules;

typedef struct s_philosopher
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		t_last_meal;
	struct s_rules	*rules;
	pthread_t		death_check;
	pid_t			proc_id;
}					t_philosopher;

typedef struct s_rules
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				died;
	long long		first_time;
	sem_t			*meal_check;
	sem_t			*forks;
	sem_t			*writing;
	t_philosopher	philosophers[250];
}					t_rules;

int					print_error(char *str);
int					error(int err);
int					init(t_rules *rules, char **argv);
int					ft_atoi(const char *str);
void				print_action(t_rules *rules, int id, char *string);
long long			get_time(void);
long long			time_delta(long long past, long long pres);
void				smart_sleep(long long time, t_rules *rules);
int					launcher(t_rules *rules);
void				kill_launcher(t_rules *rules);

#endif
