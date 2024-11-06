/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.synchronizers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:42:40 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 19:00:29 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function holds the main thread, until all threads
 * are ready to go.
 * @param table The table structure
 * @return void
 */
void	holdon_until_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mtx, &table->all_threads_ready_togo))
		;
}

/**
 * @brief This function checks if all threads are running. It verifyies
 * if the threads counter is equal to the total number of philosophers.
 * @param mutex The mutex to lock and unlock
 * @param threads The threads counter
 * @param total_philos The total number of philosophers
 * @return `bool` True if all threads are running, false otherwise
 */
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

/**
 * @brief This function increases a long value in a thread-safe way.
 * @param mutex The mutex to lock and unlock
 * @param value The value to be increased
 * @return void
 */
void	increase_long(pthread_mutex_t *mutex, long *value)
{
	safe_mutex_handler(mutex, LOCK);
	(*value)++;
	safe_mutex_handler(mutex, UNLOCK);
}

/**
 * @brief This function checks if the dinner has ended.
 * @param table The table structure
 * @return `bool` True if the dinner has ended, false otherwise
 * @note This function is not thread-safe
 */
void	philos_in_async_mode(t_philo *philo)
{
	if (philo->table->set.total_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2 == 1)
			let_philo_think_routine(philo, true);
	}
}
