/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:43:31 by bsen              #+#    #+#             */
/*   Updated: 2024/07/05 13:03:07 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	init_data(t_data *data, char **av)
{
	int	i;

	i = -1;
	data->nb_philo = ft_atoi(av[1]);
	data->nb_eat = ft_atoi(av[1]);
	if (data->nb_philo < 1)
		return (1);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = -1;
	data->start_time = get_time();
	data->dead = false;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	if (m_init(data))
		return (1);
	return (0);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].meal_eaten = 0;
		philo[i].last_time = 0;
		philo[i].had_enough = 0;
	}
	return (0);
}

int	check_args(char **av, int ac)
{
	int	j;
	int	i;

	if (ac < 5 || ac > 6)
		return (1);
	j = 0;
	i = 1;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	*control(void *arg)
{
	t_philo	*philo;
	int		i;
	int		j;

	j = 0;
	i = -1;
	philo = (t_philo *)arg;
	while (1)
	{
		while (++i < philo->data->nb_philo)
		{
			last_t_control(&philo[i]);
			if (dead_or_alive(&philo[i]))
				return (NULL);
			pthread_mutex_lock(&philo->data->had_enough_m);
			if (philo->data->nb_eat == 0)
				return (pthread_mutex_unlock(&philo->data->had_enough_m), NULL);
			pthread_mutex_unlock(&philo->data->had_enough_m);
		}
		i = -1;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	ctrl;

	if (check_args(av, ac) || init_data(&data, av))
		return (write(2, "Error\n", 6), 1);
	philo = malloc(sizeof(t_philo) * data.nb_philo);
	if (!philo)
		return (write(2, "Error\n", 6), 1);
	if (init_philo(philo, &data) || pthread_create(&ctrl, NULL, &control,
			philo))
		return (write(2, "Error\n", 6), 1);
	philos_begining(philo);
	clean_data(&data, philo);
	pthread_join(ctrl, NULL);
	return (0);
}
