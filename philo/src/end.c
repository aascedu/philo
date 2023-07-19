/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:12:22 by aascedu           #+#    #+#             */
/*   Updated: 2023/07/18 11:18:28 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_eaten_enough(t_philo *philo)
{
	philo->nbr_meal++;
	pthread_mutex_lock(&philo->data->alive);
	if (philo->nbr_meal >= philo->data->nb_must_eat)
	{
		philo->data->philo_full++;
		philo->nbr_meal = -1;
	}
	if (philo->data->philo_full == philo->data->nb_philo)
		philo->data->status = 1;
	pthread_mutex_unlock(&philo->data->alive);
	return (0);
}

int	check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->alive);
	if (philo->data->status)
	{
		pthread_mutex_unlock(&philo->data->alive);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->alive);
	return (0);
}

int	is_dead(t_philo *philo)
{
	long long	time_to_print;

	time_to_print = ft_time_from_start(philo->data->time_start);
	if (!check_status(philo) && ft_time_from_start(philo->data->time_start) \
	- philo->last_meal > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->alive);
		philo->data->status = 1;
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d died\n", time_to_print, philo->philo);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_unlock(&philo->data->alive);
		return (1);
	}
	if (check_status(philo))
		return (1);
	return (0);
}
