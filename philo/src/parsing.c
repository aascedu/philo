/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:05:32 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/29 10:56:56 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(t_data *data, int argc)
{
	if (data->nb_philo < 1)
		return ((void)printf("error - not enough philosophers\n"), 1);
	if (data->time_to_die < 1)
		return ((void)printf("error - time to die\n"), 1);
	if (data->time_to_eat < 1)
		return ((void)printf("error - time to eat\n"), 1);
	if (data->time_to_sleep < 1)
		return ((void)printf("error - time to sleep\n"), 1);
	if (data->nb_must_eat < 1 && argc == 6)
		return ((void)printf("error - number of time they must eat\n"), 1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return ((sign * number));
}

int	init_struct(t_data *data, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("error - wrong number of args\n");
		printf("./philo number_of_philosophers time_to_die time_to_eat" \
		" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	data->status = 0;
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->philo_full = 0;
	data->nb_must_eat = -1;
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	if (check_input(data, argc) == 1)
		return (1);
	return (0);
}
