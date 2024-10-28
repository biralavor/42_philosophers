/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.pthread_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:52 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/28 19:01:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	table_init(t_table *table)
{
	int	idx;
	int	*res;
	int	*arg_to_routine;

	idx = -1;
	res = 0;
	table->this_is_the_end = false;
	while (++idx < table->set->total_philos)
	{	
		safe_mutex_handler(&table->chopstick[idx].chops_mtx, INIT);
		table->chopstick[idx].chops_id = idx;

		arg_to_routine = malloc(sizeof(int)); // it will be freed inside routine called by pthread_create()
		*arg_to_routine = idx;
		safe_thread_handler(&table->philo->th_id[idx], &routine, arg_to_routine, CREATE);
		// if (pthread_create(&table->philo->th_id[idx], NULL, &routine, arg_to_routine) != 0)
		// {
		// 	perror("pthread_create error");
		// 	return (1);
		// }
		printf("Thread %d has started\n", idx);
	}
	idx = -1;
	while (++idx < table->set->total_philos)
	{
		safe_thread_handler(&table->philo->th_id[idx], NULL, (void **) &res, JOIN);
		// if (pthread_join(table->philo->th_id[idx], (void **) &res) != 0)
		// {
		// 	perror("pthread_join error");
		// 	return (3);
		// }
		printf("Thread %d has finished\n", idx);
		printf(">>> total mails from res = %d !\n", *res);
		free(res);
	}
}
