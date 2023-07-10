#include "../inc/philo.h"

int philo_eat(t_data *d, int i)
{
    if (pthread_mutex_lock(&d->forks[d->philos[i].l_fork]) != 0)
        return (0);
    if (pthread_mutex_lock(&d->forks[d->philos[i].r_fork]) != 0)
        return (0);
    if (!print_status(d, d->philos[i].id, "has taken a fork"))
        return (0);
    if (!print_status(d, d->philos[i].id, "has taken a fork"))
        return (0);
	print_status(d, d->philos[i].id, "is eating");
    d->philos[i].death_time = get_time();
    usleep(d->args.time_to_eat * 1000);
    if (pthread_mutex_unlock(&d->forks[d->philos[i].l_fork]))
        return (0);
    if (pthread_mutex_unlock(&d->forks[d->philos[i].r_fork]))
        return (0);
    d->philos[i].eat_time++;
    return (1);
}

int philo_sleep(t_data *d, int i)
{
    if (!print_status(d, d->philos[i].id, "is sleeping"))
        return (0);
    usleep(d->args.time_to_sleep * 1000);
    return (1);
}

int philo_think(t_data *d, int i)
{
    if (!print_status(d, d->philos[i].id, "is thinking"))
        return (0);
    return (1);
}

int philo_is_dead(t_data *d, int *i)
{
    int time;

    if (*i == d->args.number_of_philosophers)
        *i = 0;
    time = get_time() - d->philos[*i].death_time;
    if (time > d->args.time_to_die)
    {
        if (!print_status(d, d->philos[*i].id, "died"))
            return (0);
		*(d->philos[*i].is_death) = 1;
        return (1);
    }
    i++;
    return (0);
}