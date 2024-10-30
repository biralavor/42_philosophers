/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.table_philo_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:52 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 19:03:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_chopsticks(t_philo *philo, t_chops *chopsticks, int philo_pos)
{
	if (philo->id % 2 == 0)
	{
		philo->first_chops = &chopsticks[philo_pos];
		philo->second_chops = &chopsticks[(philo_pos + 1)
			% philo->table->set->total_philos];
	}
	else
	{
		philo->first_chops = &chopsticks[(philo_pos + 1)
			% philo->table->set->total_philos];
		philo->second_chops = &chopsticks[philo_pos];
	}
}

void	philo_init_runner(t_table *table)
{
	int	idx;
	t_philo	*philo;

	idx = -1;
	while (++idx < table->set->total_philos)
	{
		philo = table->philos + idx;
		philo->id = idx + 1;
		philo->got_meals = 0;
		philo->full = false;
		philo->table = table;
		safe_mutex_handler(philo->philo_mtx, INIT);
		get_chopsticks(philo, &table->chopsticks[idx], idx);
	}
}

void	table_init(t_table *table)
{
	int	idx;
	// int	*res;
	// int	*arg_to_routine;

	// res = 0;
	idx = -1;
	table->this_is_the_end = false;
	safe_mutex_handler(table->table_mtx, INIT);
	safe_mutex_handler(table->printer_mtx, INIT);
	while (++idx < table->set->total_philos)
	{	
		safe_mutex_handler(&table->chopsticks[idx].chops_mtx, INIT);
		table->chopsticks[idx].chops_id = idx;

		// arg_to_routine = malloc(sizeof(int)); // it will be freed inside routine called by pthread_create()
		// *arg_to_routine = idx;
		// safe_thread_handler(&table->philo->th_id[idx], &dinner_routine, arg_to_routine, CREATE);
		// if (pthread_create(&table->philo->th_id[idx], NULL, &routine, arg_to_routine) != 0)
		// {
		// 	perror("pthread_create error");
		// 	return (1);
		// }
		// printf("Thread %d has started\n", idx);
	}
	idx = -1;
	while (++idx < table->set->total_philos)
	{
		safe_thread_handler(&table->philos->th_id[idx], NULL, NULL, JOIN);
		// if (pthread_join(table->philo->th_id[idx], (void **) &res) != 0)
		// {
		// 	perror("pthread_join error");
		// 	return (3);
		// }
		// printf("Thread %d has finished\n", idx);
		// printf(">>> total mails from res = %d !\n", *res);
		// free(res);
	}
}
