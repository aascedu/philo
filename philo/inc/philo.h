/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:08:50 by aascedu           #+#    #+#             */
/*   Updated: 2023/07/18 11:22:59 by aascedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> 
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*m_fork;
	int				*fork;
	pthread_mutex_t	alive;
	int				status;
	pthread_mutex_t	launch;
	pthread_mutex_t	print;
	int				nb_philo;
	int				philo_full;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
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

// eating.c functions
int			get_fork_nbr(t_philo *philo);
int			is_eating(t_philo *philo);
int			no_race_conditions(t_philo *philo);
int			check_for_meal(t_philo *philo);
int			pick_forks(t_philo *philo);

// end.c functions
int			all_eaten_enough(t_philo *philo);
int			check_status(t_philo *philo);
int			is_dead(t_philo *philo);

// main.c functions
void		wait_end(t_data *data);

// parsing.c functions
int			check_input(t_data *data, int argc);
int			ft_atoi(char *str);
int			init_struct(t_data *data, int argc, char **argv);

// philo.c functions
void		destroy_mutex_i(t_data *data, int i);
int			init_mutex(t_data *data);
int			init_philo(t_data *data);

// sleeping.c functions
int			drop_forks(t_philo *philo);
int			is_sleeping(t_philo *philo);

// start.c functions
void		*philo_routine(t_philo *philo);
void		set_philo_info(t_data *data, int i);
int			start_philos(t_data *data);

// thinking.c functions
int			is_thinking(t_philo *philo);

// utils.c functions
void		display_msg(t_philo *philo, char *msg);
long long	ft_get_time_ms(void);
long long	ft_time_from_start(long long begin);
int			ft_strncmp(char *s1, char *s2, int n);

#endif
