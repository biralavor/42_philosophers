/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/10 18:52:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Parse the arguments and set the table values from it
 * @param table The table structure
 * @param av Arguments
 * @return void
 */
void	table_parsing(t_table *table, char **av)
{
	table->set.total_philos = ft_ato_long(av[1]);
	table->set.time_to_die = ft_ato_long(av[2]) * 1e3;
	table->set.time_to_eat = ft_ato_long(av[3]) * 1e3;
	table->set.time_to_sleep = ft_ato_long(av[4]) * 1e3;
	if (av[5])
		table->set.total_meals = ft_ato_long(av[5]);
	else
		table->set.total_meals = -1;
	if (table->set.total_philos > PHILOS_LIMIT)
		table->set.total_philos = PHILOS_LIMIT;
	if (table->set.time_to_die < 6e4
		|| table->set.time_to_eat < 6e4
		|| table->set.time_to_sleep < 6e4)
		error_manager("Time must be at least 60ms.\n");
	if (table->set.total_meals == 0)
		error_manager("Total meals must be greater then zero.\n");
}
