/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.getters_setters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:51 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/28 11:45:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function sets a boolean value in a thread-safe way.
 * @param mutex The mutex to lock and unlock
 * @param destination The destination boolean
 * @param value The value to be setted in the destination
 * @return void
 */
void	set_bool(pthread_mutex_t *mutex, bool *destination, bool value)
{
	// safe_mutex_handler(mutex, LOCK);
	pthread_mutex_lock(mutex);
	*destination = value;
	pthread_mutex_unlock(mutex);
	// safe_mutex_handler(mutex, UNLOCK);
}

/**
 * @brief This function gets a boolean value in a thread-safe way.
 * @param mutex The mutex to lock and unlock
 * @param value The value to be returned
 * @return `bool` The value of the boolean
 */
bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	result;

	// safe_mutex_handler(mutex, LOCK);
	pthread_mutex_lock(mutex);
	result = *value;
	pthread_mutex_unlock(mutex);
	// safe_mutex_handler(mutex, UNLOCK);
	return (result);
}

/**
 * @brief This function sets a long value in a thread-safe way.
 * @param mutex The mutex to lock and unlock
 * @param destination The destination long
 * @param value The value to be setted in the destination
 * @return void
 */
void	set_long(pthread_mutex_t *mutex, long *destination, long value)
{
	// safe_mutex_handler(mutex, LOCK);
	pthread_mutex_lock(mutex);
	*destination = value;
	pthread_mutex_unlock(mutex);
	// safe_mutex_handler(mutex, UNLOCK);
}

/**
 * @brief This function gets a long value in a thread-safe way.
 * @param mutex The mutex to lock and unlock
 * @param value The value to be returned
 * @return `long` The value of the long
 */
long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	result;

	// safe_mutex_handler(mutex, LOCK);
	pthread_mutex_lock(mutex);
	result = *value;
	pthread_mutex_unlock(mutex);
	// safe_mutex_handler(mutex, UNLOCK);
	return (result);
}

/**
 * @brief This function gets the boolean value that indicates
 * the end of dinner.
 * @param table The table structure
 * @return `bool` The value of the boolean
 */
bool	is_this_the_end(t_table *table)
{
	return (get_bool(&table->table_mtx, &table->this_is_the_end));
}
