/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.table_holder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:40:26 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 22:47:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table_holder(t_table *table, bool destroy)
{
	static t_table	*table_holder = NULL;

	if (table)
		table_holder = table;
	else if (table_holder && destroy)
	{
		// pthread_mutex_destroy(table_holder->table_mtx);
		// pthread_mutex_destroy(table_holder->printer_mtx);
		// free(table_holder->set);
		// free(table_holder->philos->th_id);
		free(table_holder->philos);
		// free(table_holder->printer_mtx);
		// free(table_holder->table_mtx);
		free(table_holder->chopsticks);
		// free(table_holder);
		table_holder = NULL;
	}
	return (table_holder);
}
