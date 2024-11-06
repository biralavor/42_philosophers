/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 18:52:57 by umeneses         ###   ########.fr       */
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
	table->set.total_philos = ft_atoi_long_int(av[1]);
	table->set.time_to_die = ft_atoi_long_int(av[2]) * 1e3;
	table->set.time_to_eat = ft_atoi_long_int(av[3]) * 1e3;
	table->set.time_to_sleep = ft_atoi_long_int(av[4]) * 1e3;
	if (av[5])
		table->set.total_meals = ft_atoi_long_int(av[5]);
	else
		table->set.total_meals = -1;
	if (table->set.total_philos > PHILOS_LIMIT)
		table->set.total_philos = PHILOS_LIMIT;
	if (table->set.time_to_die < 6e4
		|| table->set.time_to_eat < 6e4
		|| table->set.time_to_sleep < 6e4)
		error_manager("Time must be at least 60ms.\n");
}
