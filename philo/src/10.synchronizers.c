/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.synchronizers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:42:40 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/03 11:09:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	semaphore_like_for_threads(t_table *table)
{
	while (!get_bool(&table->table_mtx, &table->all_threads_ready_togo))
		;
}

bool	all_threads_are_running(pthread_mutex_t *mutex, long *threads,
			long total_philos)
{
	bool	result;
	
	result = false;
	safe_mutex_handler(mutex, LOCK);
	if (*threads == total_philos)
		result = true;
	safe_mutex_handler(mutex, UNLOCK);
	return (result);
}

void	increase_long(pthread_mutex_t *mutex, long *value)
{
	safe_mutex_handler(mutex, LOCK);
	(*value)++;
	safe_mutex_handler(mutex, UNLOCK);
}
