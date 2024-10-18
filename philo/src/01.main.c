/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/18 12:11:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*routine (void *arg)
{
	int	mails = 0;
	int *result = malloc(sizeof(int)); // it will be freed after pthread_join()
	int idx = 0;
	printf("Thread %ld has started with PID: %lu\n", pthread_self(), (unsigned long)pthread_self());
	while (idx < 2)
	{	
		pthread_mutex_lock(&mutex);
		mails++;
		mails = mails * (*(int *)arg);
		pthread_mutex_unlock(&mutex);
		idx++;	
	}
	*result = mails;
	free(arg);
	return ((void *) result);
}

int main (int ac, char **av)
{
	int pth_init = 0;
	int idx = -1;
	int *res = 0;
	if (ac < 2)
	{
		printf("This version needs at least a number of philosophers\n");
		return (1);
	}
	pth_init = ft_atoi_long_int(av[1]);
	pthread_t	pth[pth_init];
	pthread_mutex_init(&mutex, NULL);
	while (++idx < pth_init)
	{	
		int	*arg_to_routine = malloc(sizeof(int)); // it will be freed inside routine called by pthread_create()
		*arg_to_routine = idx;
		if (pthread_create(&pth[idx], NULL, &routine, arg_to_routine) != 0)
		{
			perror("pthread_create error");
			return (1);
		}
	}
	idx = -1;
	while (++idx < pth_init)
	{	
		if (pthread_join(pth[idx], (void **) &res) != 0)
		{
			perror("pthread_join error");
			return (3);
		}
	}
	printf(">>> total mails from res = %d !\n", *res);
	pthread_mutex_destroy(&mutex);
	free(res);
	return (0);
}
