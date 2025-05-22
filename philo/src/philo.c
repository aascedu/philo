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

void	destroy_mutex_i(t_data *data, int i)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->launch);
	pthread_mutex_destroy(&data->alive);
	while (i >= 0)
	{
		pthread_mutex_destroy(&data->m_fork[i]);
		i--;
	}
	free(data->philos);
	free(data->fork);
	free(data->m_fork);
}

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (pthread_mutex_init(&data->launch, NULL))
		return ((void)pthread_mutex_destroy(&data->print), 1);
	if (pthread_mutex_init(&data->alive, NULL))
	{
		pthread_mutex_destroy(&data->print);
		return ((void)pthread_mutex_destroy(&data->alive), 1);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->m_fork[i], NULL))
		{
			destroy_mutex_i(data, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos) {
		return (1);
	}
	data->fork = malloc(sizeof(int) * data->nb_philo);
	if (!data->fork)
		return (free(data->philos), 1);
	i = -1;
	while (++i < data->nb_philo)
		data->fork[i] = 0;
	data->m_fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->m_fork)
		return (free(data->philos), free(data->fork), 1);
	if (init_mutex(data))
		return (free(data->philos), free(data->fork), free(data->m_fork), 1);
	return (0);
}
