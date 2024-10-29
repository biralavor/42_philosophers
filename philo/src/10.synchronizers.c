/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.synchronizers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:42:40 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/29 15:53:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	semaphore_like_for_threads(t_table *table)
{
	while (!get_bool(table->table_mtx, &table->all_threads_ready_togo))
		;
}
