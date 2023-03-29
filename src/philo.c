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

void	*philo_routine(t_philo *arg)
{
	printf("philo nb : %d\n", arg->philo);
	return (NULL);
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
		return (1);
	i = 0;
	printf("%d\n", data->nb_philo);
	while (i < data->nb_philo)
	{
		philos[i].philo = i + 1;
		pthread_create(&data->threads[i], NULL, (void*)philo_routine, &philos[i]);

		printf("%p\n", &philos[i]);
		i++;
	}
	return (0);
}