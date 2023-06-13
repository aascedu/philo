/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:17:36 by aascedu           #+#    #+#             */
/*   Updated: 2023/06/13 12:17:37 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(t_philo *arg)
{
	pthread_mutex_lock(&arg->data->print);
	pthread_mutex_unlock(&arg->data->print);
	// while ((arg->nbr_meal != arg->data->nb_must_eat \
	// || arg->data->nb_must_eat == -1) && arg->status)
	// {
	// 	if (arg->philo % 2 == 0)
	// 		usleep(100);
	// }
	return (NULL);
}

void	set_philo_info(t_data *data, int i)
{
		data->philos[i].philo = i + 1;
		data->philos[i].status = 1;
		data->philos[i].last_meal = 0;
		data->philos[i].nbr_meal = 0;
		data->philos[i].data = data;
}

int	start_philos(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->print);
	while (i < data->nb_philo)
	{
		set_philo_info(data, i);
		if (pthread_create(&data->philos[i].thread, NULL, \
		(void *)philo_routine, &data->philos[i]))
		{
			destroy_mutex_i(data, i);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->print);
	return (0);
}
