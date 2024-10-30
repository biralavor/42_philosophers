/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.table_philo_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:52 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 16:24:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_chopsticks(t_philo *philo, t_chops *chopstick, int philo_pos)
{
	if (philo->id % 2 == 0)
	{
		philo->first_chops = &chopstick[philo_pos];
		philo->second_chops = &chopstick[(philo_pos + 1)
			% philo->table->set->total_philos];
	}
	else
	{
		philo->first_chops = &chopstick[(philo_pos + 1)
			% philo->table->set->total_philos];
		philo->second_chops = &chopstick[philo_pos];
	}
}

void	philo_init_runner(t_table *table)
{
	int	idx;
	t_philo	*philo;

	idx = -1;
	while (++idx < table->set->total_philos)
	{
		philo = table->philo + idx;
		philo->id = idx + 1;
		philo->got_meals = 0;
		philo->full = false;
		philo->table = table;
		safe_mutex_handler(philo->philo_mtx, INIT);
		get_chopsticks(philo, &table->chopstick[idx], idx);
	}
}

void	table_init(t_table *table)
{
	int	idx;
	int	*res;
	int	*arg_to_routine;

	idx = -1;
	res = 0;
	table->this_is_the_end = false;
	safe_mutex_handler(table->table_mtx, INIT);
	safe_mutex_handler(table->printer_mtx, INIT);
	while (++idx < table->set->total_philos)
	{	
		safe_mutex_handler(&table->chopstick[idx].chops_mtx, INIT);
		table->chopstick[idx].chops_id = idx;

		arg_to_routine = malloc(sizeof(int)); // it will be freed inside routine called by pthread_create()
		*arg_to_routine = idx;
		safe_thread_handler(&table->philo->th_id[idx], &dinner_routine, arg_to_routine, CREATE);
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
