/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.getters_setters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:51 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 22:48:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *destination, bool value)
{
	safe_mutex_handler(mutex, LOCK);
	*destination = value;
	safe_mutex_handler(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	result;

	result = false;
	safe_mutex_handler(mutex, LOCK);
	result = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (result);
}

void	set_long(pthread_mutex_t *mutex, long *destination, long value)
{
	safe_mutex_handler(mutex, LOCK);
	*destination = value;
	safe_mutex_handler(mutex, UNLOCK);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	result;

	result = 0;
	safe_mutex_handler(mutex, LOCK);
	result = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (result);
}

bool	this_is_the_end_of_dinner(t_table *table)
{
	bool	result;

	result = get_bool(&table->table_mtx, &table->this_is_the_end);
	return (result);
}
