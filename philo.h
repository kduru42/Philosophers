/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 04:37:30 by kduru             #+#    #+#             */
/*   Updated: 2023/07/14 20:50:50 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				meals_eaten;
	int				total_eaten;
	int				*is_dead;
	t_time			last_meal;
	t_time			start_time;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
}				t_philo;

t_time			ft_get_time(void);
void			ft_sleep(int wait_time);
int				ft_check_args(int argc, char **argv);
void			ft_init_philos(t_philo *philo, int argc, char **argv);
void			ft_init_forks_mutex(t_philo *philo, char **argv);
void			ft_init_mutex(t_philo *philo, char **argv,
					pthread_mutex_t *forks, pthread_mutex_t *death);
long			ft_atol(const char *str);
void			ft_print_status(t_philo *philo, char *status);
void			ft_check_death(t_philo *philo);
void			*ft_dinner(void *args);
void			ft_join_threads(t_philo *philo, char **argv);
void			ft_free(t_philo *philo, pthread_mutex_t *forks,
					pthread_mutex_t *death);
int				ft_lonely_dinner(t_philo *philo);

#endif