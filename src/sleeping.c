/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:12:34 by aascedu           #+#    #+#             */
/*   Updated: 2023/06/28 14:12:35 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_sleeping(t_philo *philo)
{
    long long   time;

    display_msg(philo, "is sleeping");
    drop_forks(philo);
    time = ft_time_from_start(philo->data->time_start);
    while ((ft_time_from_start(philo->data->time_start) - time) < philo->data->time_to_sleep)
		;
    return (0);
}
