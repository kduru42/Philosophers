/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 04:37:01 by kduru             #+#    #+#             */
/*   Updated: 2023/07/14 20:55:28 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (argc != 5 && argc != 6)
		return (1);
	if (ft_check_args(argc, argv) == 0)
		return (2);
	philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo)
		return (3);
	ft_init_philos(philo, argc, argv);
	ft_init_mutex(philo, argv, forks, death);
	if (ft_atol(argv[1]) == 1)
	{
		ft_lonely_dinner(philo);
		ft_free(philo, forks, death);
		return (0);
	}
	ft_join_threads(philo, argv);
	ft_free(philo, forks, death);
	return (0);
}
