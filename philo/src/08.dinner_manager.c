/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.dinner_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:01:45 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 16:39:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dinner_manager(t_table *table)
{
	int	idx;

	idx = -1;
	if (table->set->total_meals == -1)
	{
		// TODO
	}
	else if (table->set->total_meals > 0)
		return ; // back to main and clean
	else if (table->set->total_meals == 1)
	{
		// TODO ad hoc specific function for one meal
	}
	else
	{
		// CREAT all threads
		while(++idx < table->set->total_philos)
		{
			safe_thread_handler(table->philo[idx].th_id, dinner_routine, &table->philo[idx], CREATE);
		}
	}
	// starting the simulation
	table->start_time = ft_gettime(MILISSECOND);
	// All threads are ready
	set_bool(table->table_mtx, &table->all_threads_ready_togo, true);
	idx = -1;
	// JOIN all threads
	while (++idx < table->set->total_philos)
	{
		safe_thread_handler(table->philo[idx].th_id, NULL, NULL, JOIN);
	}
}

void	dinner_startup_runner(t_table *table)
{
	//avoid race condition
	semaphore_like_for_threads(table);

	// set meals time
	while (!this_is_the_end_of_dinner(table))
	{
		if (table->philo->full) // TODO: thread safe
			break ;
		let_philo_eat_routine(table->philo);
		let_philo_think_routine(table->philo);
		let_philo_sleep_routine(table->philo);
	}
}
