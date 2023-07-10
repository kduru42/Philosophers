/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:54:57 by kduru             #+#    #+#             */
/*   Updated: 2023/07/10 00:54:57 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	if (!init_args(&d, argc, argv))
	{
		printf("Invalid argument\n");
		return (1);
	}
	create_philos(d);
	if (!init_forks(d))
		return (0);
	if (d->args.number_of_philosophers == 1)
	{
		one_philo(d);
		return (0);
	}
	if (!create_threads(d))
		return (1);
	if (!destroy_mutexes(d))
		return (1);
	free_data(d);
	return (0);
}
