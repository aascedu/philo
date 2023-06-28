/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:44:06 by aascedu           #+#    #+#             */
/*   Updated: 2023/06/13 09:44:07 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", ft_time_from_start(philo->data->time_start), philo->philo, msg);
	pthread_mutex_unlock(&philo->data->print);
}

long long	ft_get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	ft_time_from_start(long long begin)
{
	if (!begin)
		begin = ft_get_time_ms();
	return (ft_get_time_ms() - begin);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1 && s2 && i < n && s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
