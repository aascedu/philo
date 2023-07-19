/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:09:19 by aascedu           #+#    #+#             */
/*   Updated: 2023/06/08 11:18:40 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;

	if (init_struct(&data, argc, argv) || init_philo(&data))
		return (1);
	status = 0;
	if (start_philos(&data))
		status = 1;
	wait_end(&data);
	destroy_mutex_i(&data, data.nb_philo - 1);
	return (status);
}
