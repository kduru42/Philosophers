/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:54:36 by kduru             #+#    #+#             */
/*   Updated: 2023/07/10 00:54:36 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_forks(t_philo *d)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&d->print_m, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&d->death, NULL) != 0)
		return (0);
	while (i < d->number_of_philosophers)
	{
		if (pthread_mutex_init(&d->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	print_status(t_philo *d, int id, char *status)
{
	if (*(d->philos[id - 1].is_death) == 1)
		return (0);
	pthread_mutex_lock(&d->print_m);
	printf("%lld %d %s\n", get_time() - d->t, id, status);
	pthread_mutex_unlock(&d->print_m);
	return (1);
}
