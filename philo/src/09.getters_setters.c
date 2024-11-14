/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.getters_setters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:51 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/14 05:15:34 by umeneses         ###   ########.fr       */
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
	safe_mutex_handler(mutex, LOCK);
	*destination = value;
	safe_mutex_handler(mutex, UNLOCK);
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

	result = false;
	safe_mutex_handler(mutex, LOCK);
	result = *value;
	safe_mutex_handler(mutex, UNLOCK);
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
	safe_mutex_handler(mutex, LOCK);
	*destination = value;
	safe_mutex_handler(mutex, UNLOCK);
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

	result = 0;
	safe_mutex_handler(mutex, LOCK);
	result = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (result);
}

/**
 * @brief This function gets the boolean value that indicates
 * the end of dinner.
 * @param table The table structure
 * @return `bool` The value of the boolean
 */
bool	this_is_the_end_of_dinner(t_table *table)
{
	return (get_bool(&table->table_mtx, &table->this_is_the_end));
}
