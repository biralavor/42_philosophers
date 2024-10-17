/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/17 16:53:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>

void	*routine (void *arg)
{
	(void)arg;
	printf("Hello, from thread!\n");
	sleep(3);
	printf("Bye, from thread!\n");
	return (NULL);
}

int main (void)
{
	pthread_t	t01, t02;

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
	printf(">>> Hello, world!\n");
	return (0);
}
