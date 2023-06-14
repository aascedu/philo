/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:06:33 by aascedu           #+#    #+#             */
/*   Updated: 2023/06/14 09:06:34 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork_nbr(t_philo *philo)
{
	if (philo->philo == philo->data->nb_philo)
		return (1);
	else
		return (philo->philo);
}

int	is_eating(t_philo *philo)
{
	long long int	time;

	pthread_mutex_lock(&philo->data->m_fork[philo->philo - 1]);
	if (philo->data->fork[philo->philo - 1] == 0)
		philo->data->fork[philo->philo - 1] = philo->philo;
	pthread_mutex_unlock(&philo->data->m_fork[philo->philo - 1]);
	time = ft_time_from_start();
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d has taken a fork[%d]=%d\n", time, philo->philo, philo->philo, philo->data->fork[philo->philo - 1]);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->data->m_fork[get_fork_nbr(philo)]);
	if (philo->data->fork[philo->philo] == philo->philo && philo->data->fork[get_fork_nbr(philo)] == 0)
		philo->data->fork[get_fork_nbr(philo)] = philo->philo;
	pthread_mutex_unlock(&philo->data->m_fork[get_fork_nbr(philo)]);
	time = ft_time_from_start();
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d has taken a fork[%d]=%d\n", time, philo->philo, philo->philo, philo->data->fork[get_fork_nbr(philo)]);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}