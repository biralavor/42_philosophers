/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.dinner_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:01:45 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/29 19:21:03 by umeneses         ###   ########.fr       */
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
		// TODO
	}
	else
	{
		while(++idx < table->set->total_philos)
		{
			safe_thread_handler(table->philo[idx].th_id, dinner_routine, &table->philo[idx], CREATE);
		}
	}

	table->start_time = ft_gettime(MILISSECOND);
	// TODO a way to avoid race condition
	set_bool(table->table_mtx, &table->all_threads_ready_togo, true);
}
