/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 04:35:25 by kduru             #+#    #+#             */
/*   Updated: 2023/07/13 04:38:21 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_lonely_dinner(t_philo *philo)
{
	ft_sleep(philo->time_to_die);
	return (1);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	ft_print_status(philo, "has taken a fork");
	if (philo->philo_nb == 1)
		if (ft_lonely_dinner(philo))
			return (1);
	pthread_mutex_lock(philo->right_fork_mutex);
	ft_print_status(philo, "has taken a fork");
	ft_print_status(philo, "is eating");
	return (0);
}

void	ft_sleep_philos(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	philo->meals_eaten++;
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->death);
	ft_sleep(philo->time_to_eat);
	ft_print_status(philo, "is sleeping");
	pthread_mutex_unlock(philo->right_fork_mutex);
	pthread_mutex_unlock(philo->left_fork_mutex);
	ft_sleep(philo->time_to_sleep);
}

void	*ft_dinner(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		ft_eat(philo);
		ft_sleep_philos(philo);
		ft_print_status(philo, "is thinking");
	}
	return (NULL);
}
