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
	t_philo			*philos;
	pthread_mutex_t	*m_fork;
	int				*fork;
	pthread_mutex_t	alive;
	pthread_mutex_t	launch;
	int				status;
	pthread_mutex_t	print;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	long long		time_start;
};

struct s_philo
{
	int				philo;
	pthread_t		thread;
	int				status;
	int				nbr_meal;
	long long		last_meal;
	t_data			*data;
};

// actions.c functions
int					get_fork_nbr(t_philo *philo);
int					is_eating(t_philo *philo);
int					is_thinking(t_philo *philo);

// main.c functions
void				wait_end(t_data *data);

// parsing.c functions
int					check_input(t_data *data);
int					ft_atoi(char *str);
int					init_struct(t_data *data, int argc, char **argv);

// philo.c functions
int					init_philo(t_data *data);

// start.c functions
int					start_philos(t_data *data);
void				free_philos(t_data *data);
void				destroy_mutex_i(t_data *data, int i);

// utils.c functions
unsigned long long	ft_get_time_ms(void);
unsigned long long	ft_time_from_start(long long begin);
int					ft_strncmp(char *s1, char *s2, int n);

#endif
