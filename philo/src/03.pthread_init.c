/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.pthread_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:52 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/22 17:54:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	table_mutex_init(t_table *table)
{
	// pthread_t	*philos;
	
	// philos = NULL;
	// philos = philos[table->setup->total_philos];
	pthread_mutex_init(table->mtx_philo, NULL);
}

t_table	*table_holder(t_table *table, bool destroy)
{
	static t_table	*table_holder = NULL;

	if (table)
		table_holder = table;
	else if (destroy)
	{
		pthread_mutex_destroy(table->mtx_philo);
		free(table->setup);
		table_holder = NULL;
	}
	return (table_holder);
}
