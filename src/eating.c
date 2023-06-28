/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:06:33 by aascedu           #+#    #+#             */
/*   Updated: 2023/06/14 09:06:34 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork_nbr(t_philo *philo);
int	pick_forks(t_philo *philo);
int	drop_forks(t_philo *philo);

int	is_eating(t_philo *philo)
{
	long long	time;

	while (!pick_forks(philo) && !is_dead(philo))
		;
	time = ft_time_from_start(philo->data->time_start);
	while ((ft_time_from_start(philo->data->time_start) - time) < philo->data->time_to_eat)
		;
	return (0);
}

int	get_fork_nbr(t_philo *philo)
{
	if (philo->philo == philo->data->nb_philo && philo->data->nb_philo != 1)
		return (0);
	else
		return (philo->philo);
}

int	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_fork[philo->philo - 1]);
	if (philo->data->fork[philo->philo - 1] == 0)
	{
		philo->data->fork[philo->philo - 1] = philo->philo;
		display_msg(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&philo->data->m_fork[philo->philo - 1]);
	pthread_mutex_lock(&philo->data->m_fork[get_fork_nbr(philo)]);
	if (philo->data->fork[get_fork_nbr(philo)] == 0)
	{
		philo->data->fork[get_fork_nbr(philo)] = philo->philo;
		display_msg(philo, "has taken a fork");	
	}
	pthread_mutex_unlock(&philo->data->m_fork[get_fork_nbr(philo)]);
	if (philo->data->fork[philo->philo - 1] == philo->philo && philo->data->fork[get_fork_nbr(philo)] == philo->philo)
	{
		display_msg(philo, "is eating");
		philo->last_meal = ft_time_from_start(philo->data->time_start);
		return (1);
	}
	return (0);
}

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


