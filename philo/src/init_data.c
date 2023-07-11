/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:52:38 by kduru             #+#    #+#             */
/*   Updated: 2023/07/10 00:52:38 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_args(t_philo **d, int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (0);
    *d = (t_philo*)malloc(sizeof(t_philo));
	(*d)->number_of_philosophers = ft_atoi(argv[1]);
	(*d)->time_to_die = ft_atoi(argv[2]);
	(*d)->time_to_eat = ft_atoi(argv[3]);
	(*d)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*d)->philosopher_must_eat = ft_atoi(argv[5]);
	else
		(*d)->philosopher_must_eat = 0;
	(*d)->philos = (t_philo *)malloc(sizeof(t_philo)
			* (*d)->number_of_philosophers);
	(*d)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (*d)->number_of_philosophers);
	(*d)->t = get_time();
	return (1);
}
