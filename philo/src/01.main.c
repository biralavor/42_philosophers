/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/27 21:41:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	int	mails = 0;
	int *result = malloc(sizeof(int)); // it will be freed after pthread_join()
	int idx = 0;
	printf("Thread %d is running\n", *(int *)arg);
	while (idx < 2)
	{
		pthread_mutex_lock(table_holder(NULL, false)->ph_mtx);
		mails++;
		mails = mails * (*(int *)arg);
		pthread_mutex_unlock(table_holder(NULL, false)->ph_mtx);
		idx++;
	}
	*result = mails;
	free(arg);
	return ((void *) result);
}

int main(int ac, char **av)
{
	t_table	*table;
	int		idx;
	int		*res;

	idx = -1;
	res = 0;
	table = NULL;
	if (!arguments_validation_manager(ac, av))
		exit(EXIT_FAILURE);
	table_parsing(table, av);
	table = table_holder(NULL, false);
	// table_mutex_init(table);
	while (++idx < table->set->total_philos)
	{	
		int	*arg_to_routine = malloc(sizeof(int)); // it will be freed inside routine called by pthread_create()
		*arg_to_routine = idx;
		if (pthread_create(&table->philo->th_id[idx], NULL, &routine, arg_to_routine) != 0)
		{
			perror("pthread_create error");
			return (1);
		}
		printf("Thread %d has started\n", idx);
	}
	idx = -1;
	while (++idx < table->set->total_philos)
	{
		if (pthread_join(table->philo->th_id[idx], (void **) &res) != 0)
		{
			perror("pthread_join error");
			return (3);
		}
		printf("Thread %d has finished\n", idx);
		printf(">>> total mails from res = %d !\n", *res);
		free(res);
	}
	pthread_mutex_destroy(table->ph_mtx);
	table_holder(NULL, true);
	exit(EXIT_SUCCESS);
}
