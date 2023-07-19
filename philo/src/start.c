/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:17:36 by aascedu           #+#    #+#             */
/*   Updated: 2023/07/18 11:20:58 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->launch);
	pthread_mutex_unlock(&philo->data->launch);
	if (philo->philo % 2 != 0)
		usleep(40000);
	while (!is_dead(philo))
	{
		is_thinking(philo);
		if (is_dead(philo))
			break ;
		is_eating(philo);
		if (is_dead(philo))
			break ;
		is_sleeping(philo);
	}
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

	i = -1;
	while (++i < data->nb_philo)
		set_philo_info(data, i);
	i = 0;
	pthread_mutex_lock(&data->launch);
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, \
					(void *)philo_routine, &data->philos[i]))
		{
			destroy_mutex_i(data, i);
			return (1);
		}
		i++;
	}
	data->time_start = ft_get_time_ms();
	pthread_mutex_unlock(&data->launch);
	return (0);
}
