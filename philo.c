/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 04:37:21 by kduru             #+#    #+#             */
/*   Updated: 2023/07/13 04:37:23 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philos(t_philo *philo, int argc, char **argv)
{
	int	is_dead;
	int	i;

	i = 0;
	is_dead = 0;
	while (i < ft_atol(argv[1]))
	{
		philo[i].id = i;
		philo[i].time_to_die = ft_atol(argv[2]);
		philo[i].time_to_eat = ft_atol(argv[3]);
		philo[i].time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			philo[i].must_eat = ft_atol(argv[5]);
		else
			philo[i].must_eat = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].meals_eaten = 0;
		philo[i].philo_nb = ft_atol(argv[1]);
		philo[i].is_dead = &is_dead;
		i++;
	}
	philo->total_eaten = 0;
}
