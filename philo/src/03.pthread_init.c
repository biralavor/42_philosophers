/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.pthread_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:52 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/24 21:46:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	table_mutex_init(t_table *table)
{
	// pthread_t	*th_id;
	
	pthread_mutex_init(table->ph_mtx, NULL);
}

t_table	*table_holder(t_table *table, bool destroy)
{
	static t_table	*table_holder = NULL;

	if (table)
		table_holder = table;
	else if (destroy)
	{
		pthread_mutex_destroy(table_holder->ph_mtx);
		free(table_holder->set);
		free(table_holder->philo->th_id);
		free(table_holder->philo);
		free(table_holder->ph_mtx);
		free(table_holder);
		table_holder = NULL;
	}
	return (table_holder);
}
