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
		return (0);
	else
		return (philo->philo);
}

int	is_eating(t_philo *philo)
{
	long long int	time;

	time = ft_time_from_start(philo->data->time_start);
	pthread_mutex_lock(&philo->data->m_fork[philo->philo - 1]);
	if (philo->data->fork[philo->philo - 1] == 0)
	{
		philo->data->fork[philo->philo - 1] = philo->philo;
		pthread_mutex_unlock(&philo->data->m_fork[philo->philo - 1]);
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d has taken a fork (fork[%d]:%d)\n", time, philo->philo, philo->philo - 1, philo->data->fork[philo->philo - 1]);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_mutex_lock(&philo->data->m_fork[get_fork_nbr(philo)]);
	if (philo->data->fork[get_fork_nbr(philo)] == 0 && philo->data->fork[philo->philo - 1] == philo->philo)
	{
		philo->data->fork[get_fork_nbr(philo)] = philo->philo;
		pthread_mutex_unlock(&philo->data->m_fork[get_fork_nbr(philo)]);
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d has taken a fork (fork[%d]:%d)\n", time, philo->philo, get_fork_nbr(philo), philo->data->fork[get_fork_nbr(philo)]);
		pthread_mutex_unlock(&philo->data->print);		
	}
	return (0);
}

int	is_thinking(t_philo *philo)
{
	long long int	time;

	time = ft_time_from_start(philo->data->time_start);
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d is thinking\n", time, philo->philo);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}