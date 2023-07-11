/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:03:27 by kduru             #+#    #+#             */
/*   Updated: 2023/07/10 01:03:27 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	create_threads(t_philo *d)
{
	t_philo	*p;
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		d->which_philo = i;
		p = &(d->philos[i]);
		if (pthread_create(&d->philos[i].thread, NULL,
				&routine, (void *)p) != 0)
			return (0);
		i++;
		usleep(100);
	}
	if (pthread_create(&d->checker, NULL, &check_is_dead, (void *)d) != 0)
		return (0);
	usleep(100);
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (pthread_join(d->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(d->checker, NULL) != 0)
		return (0);
	return (1);
}

void	create_philos(t_philo *d)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < d->number_of_philosophers - 1)
	{
		init_philo_datas(d, i, j);
		i++;
		j++;
	}
	j = 0;
	init_philo_datas(d, i, j);
}

int	destroy_mutexes(t_philo *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&d->forks[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_destroy(&d->print_m) != 0)
		return (0);
	if (pthread_mutex_destroy(&d->death) != 0)
		return (0);
	return (1);
}

void	init_philo_datas(t_philo *d, int i, int j)
{
	int	is_death;

	is_death = 0;
	d->philos[i].id = i + 1;
	d->philos[i].eat_time = 0;
	d->philos[i].death_time = 0;
	d->philos[i].l_fork = i;
	d->philos[i].r_fork = j;
	d->philos[i].is_death = &is_death;
}
