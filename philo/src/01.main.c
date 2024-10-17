/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/17 18:06:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>

int	mails = 0;


void	*routine (void *arg)
{
	int idx = -1;
	(void)arg;
	while (++idx < 1000000)
	{	
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main (void)
{
	pthread_t	t01, t02;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t01, NULL, &routine, NULL) != 0)
	{
		perror("pthread_create error on t01");
		return (1);
	}
	if (pthread_create(&t02, NULL, &routine, NULL) != 0)
	{
		perror("pthread_create error on t02");
		return (2);
	}
	if (pthread_join(t01, NULL) != 0)
	{
		perror("pthread_join error on t01");
		return (3);
	}
	if (pthread_join(t02, NULL) != 0)
	{
		perror("pthread_join error on t02");
		return (4);
	}
	printf(">>> mails = %d !\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
