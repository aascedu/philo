/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:40:10 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/29 15:06:29 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_think()

void	*philo_routine(t_philo *arg)
{
	while ((arg->nbr_meal != arg->data->nb_must_eat \
	|| arg->data->nb_must_eat == -1) && arg->status)
	{
		if (arg->philo % 2 == 0)
			usleep(100);
		if ()
	}
	return (NULL);
}

void	init_mutex(t_data *data, t_philo *philos)
{
	int	i;

	pthread_mutex_init(&data->print, NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&philos[i].fork_mutex, NULL);
		i++;
	}
}

void	destroy_mutex(t_data *data, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(&data->print);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&philos[i].fork_mutex);
		i++;
	}
}

int	init_philo(t_data *data, t_philo *philos)
{
	int	i;

	philos = (t_philo *)malloc(sizeof(philos) * data->nb_philo);
	if (!philos)
		return (1);
	data->philos = philos;
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->threads)
		return (free(philos), 1);
	init_mutex(data, philos);
	i = 0;
	while (i < data->nb_philo)
	{
		philos[i].philo = i + 1;
		philos[i].status = 1;
		philos[i].last_meal = 0;
		philos[i].nbr_meal = 0;
		philos[i].data = data;
		if (pthread_create(&data->threads[i], NULL, \
		(void *)philo_routine, &philos[i]))
			return (free(philos), free(data->threads), 1);
		i++;
	}
	return (0);
}
