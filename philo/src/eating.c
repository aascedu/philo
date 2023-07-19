/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:06:33 by aascedu           #+#    #+#             */
/*   Updated: 2023/07/18 11:20:34 by aascedu          ###   ########.fr       */
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
	while (!check_status(philo) && !pick_forks(philo))
		usleep(10 * philo->data->nb_philo);
	return (0);
}

int	no_race_conditions(t_philo *philo)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	pthread_mutex_lock(&philo->data->m_fork[philo->philo - 1]);
	if (philo->data->fork[philo->philo - 1] == philo->philo)
		i = 1;
	pthread_mutex_unlock(&philo->data->m_fork[philo->philo - 1]);
	pthread_mutex_lock(&philo->data->m_fork[get_fork_nbr(philo)]);
	if (philo->data->fork[get_fork_nbr(philo)] == philo->philo)
		k = 1;
	pthread_mutex_unlock(&philo->data->m_fork[get_fork_nbr(philo)]);
	if (i && k)
		return (1);
	return (0);
}

int	check_for_meal(t_philo *philo)
{
	if (is_dead(philo))
		return (0);
	if (no_race_conditions(philo) && philo->philo - 1 != get_fork_nbr(philo))
	{
		display_msg(philo, "is eating");
		philo->last_meal = ft_time_from_start(philo->data->time_start);
		while (!check_status(philo) \
		&& (ft_time_from_start(philo->data->time_start) - philo->last_meal) \
		< philo->data->time_to_eat)
			usleep(10 * philo->data->nb_philo);
		if (philo->data->nb_must_eat != -1)
			all_eaten_enough(philo);
		return (1);
	}
	return (0);
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
	if (check_for_meal(philo))
		return (1);
	return (0);
}
