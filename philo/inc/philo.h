/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:50:47 by kduru             #+#    #+#             */
/*   Updated: 2023/07/10 00:50:47 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	philosopher_must_eat;

}	t_args;

typedef struct s_philo
{
	pthread_t	thread;
	t_args		args;
	int			*is_death;
	int			eat_time;
	int			death_time;
	int			id;
	int			r_fork;
	int			l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	print_m;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	long long		t;
	pthread_t		checker;
	t_philo			*philos;
	t_args			args;
}	t_data;

long long	get_time(void);
long		ft_atoi(const char *str);
void		*routine(void *arg);
void		init_philo_datas(t_data *d, int i, int j);
void		create_philos(t_data *d);
void		free_data(t_data *d);
void		one_philo(t_data *d);
void		*check_is_dead(void *arg);
int			philo_think(t_data *d, int i);
int			philo_sleep(t_data *d, int i);
int			init_args(t_data **d, int argc, char **argv);
int			check_args(int argc, char **argv);
int			ft_isdigit(int c);
int			create_threads(t_data *d);
int			init_forks(t_data *d);
int			destroy_mutexes(t_data *d);
int			philo_eat(t_data *d, int i);
int			philo_is_dead(t_data *d, int *i);
int			routine_execute(t_philo *p, int i);
int			print_status(t_data *d, int id, char *status);

#endif