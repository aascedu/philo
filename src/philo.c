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
	printf("i = %d\n", i);
	pthread_mutex_destroy(&data->m_print);
	while (i >= 0)
	{
		pthread_mutex_destroy(&data->philos[i].fork_mutex);
		i--;
	}
}

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->m_print, NULL))
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->philos[i].fork_mutex, NULL))
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&data->philos[i].fork_mutex);
				i--;
			}
			pthread_mutex_destroy(&data->m_print);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (1);
	if (init_mutex(data))
		return (free(data->philos), 1);
	return (0);
}
