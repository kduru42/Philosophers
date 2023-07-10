/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:55:40 by kduru             #+#    #+#             */
/*   Updated: 2023/07/10 00:55:40 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)arg;
/* 	if ((i + 1) % 2 == 0)
	{
		print_status(d, i, "is thinking");
		usleep(1600);
	} */
	if (p->args.philosopher_must_eat != 0)
	{
		while (p->eat_time < p->args.philosopher_must_eat
			&& *(p->is_death) == 0)
			if (!routine_execute(p, i))
				break ;
	}
	else
	{
		while (*(p->is_death) == 0)
			if (!routine_execute(p, i))
				break ;
	}
	return (NULL);
}

int	routine_execute(t_philo *p, int i)
{
	if (!philo_eat(p, i))
		return (0);
	if (p->eat_time != p->args.philosopher_must_eat)
	{
		if (!philo_sleep(p, i))
			return (0);
		if (!philo_think(p, i))
			return (0);
	}
	return (1);
}

void	*check_is_dead(void *arg)
{
	t_data	*d;
	int		i;

	d = (t_data *)arg;
	i = 0;
	if (d->args.philosopher_must_eat != 0)
	{
		while (d->philos[i].eat_time < d->args.philosopher_must_eat
			&& *(d->philos[i].is_death) == 0)
			if (philo_is_dead(d, &i) == 1)
				break ;
	}
	else
	{
		while (*(d->philos[i].is_death) == 0)
			if (philo_is_dead(d, &i) == 1)
				break ;
	}
	return (NULL);
}

void	one_philo(t_data *d)
{
	printf("%lld 1 has taken a fork\n", get_time() - d->t);
	usleep(d->args.time_to_die * 1000);
	printf("%lld 1 died\n", get_time() - d->t);
	free_data(d);
}
