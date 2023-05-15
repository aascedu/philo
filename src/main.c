/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:09:19 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/29 15:06:56 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->nb_philo)
	{
		if (data->philos[i].nbr_meal == data->nb_must_eat)
			j++;
		i++;
	}
	if (j == data->nb_philo)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;
	int		status;

	if (init_struct(&data, argc, argv))
		return (1);
	philos = NULL;
	if (init_philo(&data, philos))
		return (1);
	status = data.status;
	// while (status)
	// {
		pthread_mutex_lock(&data.print);
		status = check_status(&data);
		pthread_mutex_unlock(&data.print);
		usleep(100);
		status++;
		// printf("%d\n", status);
	// }
	return (0);
}
