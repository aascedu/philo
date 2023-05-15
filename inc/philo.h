/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:08:50 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/29 14:45:35 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> 
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIE "died"

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data
{
	int				status;
	pthread_mutex_t	status;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	print;
};

struct s_philo
{
	int				philo;
	int				status;
	int				nbr_meal;
	long long		last_meal;
	t_data			*data;
	pthread_mutex_t	fork_mutex;
};

// parsing.c functions
int		check_input(t_data *data);
int		ft_atoi(char *str);
int		init_struct(t_data *data, int argc, char **argv);

// philo.c function
int		init_philo(t_data *data, t_philo *philos);

int		ft_print(t_philo *philo, char *msg);

#endif
