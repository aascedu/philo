/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:12:22 by aascedu           #+#    #+#             */
/*   Updated: 2023/06/28 14:12:23 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philo *philo)
{
    if (philo->last_meal == 0)
        return (0);
    if (ft_time_from_start(philo->data->time_start) - philo->last_meal > philo->data->time_to_die)
    {
        pthread_mutex_lock(&philo->data->alive);
        philo->data->status = 1;
        pthread_mutex_unlock(&philo->data->alive);
        display_msg(philo, "died");
        return (1);
    }
    return (0);
}
