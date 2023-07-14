/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 04:34:53 by kduru             #+#    #+#             */
/*   Updated: 2023/07/13 04:56:22 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead(t_philo *philo, int i, t_time time)
{
	if ((int)time > philo[i].time_to_die)
	{
		printf("%llu %d %s\n", time, philo->id + 1, "died");
		*philo->is_dead = 1;
		return (1);
	}
	return (0);
}

int	ft_finish_serving(t_philo *philo)
{
	int	flag;
	int	j;

	flag = 0;
	j = 0;
	if (philo->must_eat != -1)
	{
		while (j < philo->philo_nb)
			if (philo[j++].meals_eaten < philo->must_eat)
				flag = 1;
		if (flag == 0)
		{
			*philo->is_dead = 1;
			return (1);
		}
	}
	return (0);
}

void	ft_check_death(t_philo *philo)
{
	t_time	time;
	int		i;

	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_mutex_lock(philo->death);
		time = ft_get_time() - philo[i].last_meal;
		if (ft_dead(philo, i, time) || ft_finish_serving(philo))
			break ;
		i++;
		pthread_mutex_unlock(philo->death);
	}
}

void	ft_print_status(t_philo *philo, char *status)
{
	t_time	time;

	time = ft_get_time() - philo->start_time;
	pthread_mutex_lock(philo->death);
	if (*philo->is_dead == 0)
		printf("%llu %d %s\n", time, philo->id + 1, status);
	pthread_mutex_unlock(philo->death);
}
