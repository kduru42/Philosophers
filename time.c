/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 04:37:49 by kduru             #+#    #+#             */
/*   Updated: 2023/07/14 19:04:18 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int wait_time)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < (t_time)wait_time)
		usleep(1000);
}

t_time	ft_get_time(void)
{
	struct timeval		tv;
	t_time				time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
