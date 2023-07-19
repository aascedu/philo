/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:12:34 by aascedu           #+#    #+#             */
/*   Updated: 2023/07/18 11:21:39 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_fork[philo->philo - 1]);
	if (philo->data->fork[philo->philo - 1] == philo->philo)
		philo->data->fork[philo->philo - 1] = 0;
	pthread_mutex_unlock(&philo->data->m_fork[philo->philo - 1]);
	pthread_mutex_lock(&philo->data->m_fork[get_fork_nbr(philo)]);
	if (philo->data->fork[get_fork_nbr(philo)] == philo->philo)
		philo->data->fork[get_fork_nbr(philo)] = 0;
	pthread_mutex_unlock(&philo->data->m_fork[get_fork_nbr(philo)]);
	return (0);
}

int	is_sleeping(t_philo *philo)
{
	long long	time;

	if (check_status(philo))
		return (1);
	display_msg(philo, "is sleeping");
	drop_forks(philo);
	time = ft_time_from_start(philo->data->time_start);
	while (!is_dead(philo) \
	&& (ft_time_from_start(philo->data->time_start) - time) \
	< philo->data->time_to_sleep)
		usleep(10 * philo->data->nb_philo);
	return (0);
}
