/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.dinner_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:01:45 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 20:28:36 by umeneses         ###   ########.fr       */
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
			safe_thread_handler(table->philos[idx].th_id, dinner_runner, &table->philos[idx], CREATE);
		}
	}
	table->start_time = ft_gettime(MILISSECOND);
	set_bool(table->table_mtx, &table->all_threads_ready_togo, true);
	idx = -1;
	while (++idx < table->set->total_philos)
	{
		safe_thread_handler(table->philos[idx].th_id, NULL, NULL, JOIN);
	}
}

void	*dinner_runner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	//semaphore for syncronization
	semaphore_like_for_threads(philo->table);
	while (!this_is_the_end_of_dinner(philo->table))
	{
		if (philo->full) // TODO: thread safe
			break ;
		let_philo_eat_routine(philo);
		let_philo_sleep_routine(philo);
		let_philo_think_routine(philo);
	}
	return (NULL);
}
