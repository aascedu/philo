#include "philo.h"

int	ft_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	perror("HELLO");
	printf("timestamp ");
	printf("%d ", philo->philo);
	printf("%s\n", msg);
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}