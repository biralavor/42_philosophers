/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:16 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/29 11:19:14 by umeneses         ###   ########.fr       */
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
	table->total_philos = ft_atoi_long(av[1]);
	table->timeto_die = ft_atoi_long(av[2]) * 1e3;
	table->timeto_eat = ft_atoi_long(av[3]) * 1e3;
	table->timeto_sleep = ft_atoi_long(av[4]) * 1e3;
	if (av[5])
		table->total_meals = ft_atoi_long(av[5]);
	else
		table->total_meals = -1;
	if (table->total_philos == 0)
		error_manager("Total Philos must be greater then zero.");
	else if (table->total_philos > PHILOS_LIMIT)
	{
		table->total_philos = PHILOS_LIMIT;
		printf(PURPLE"Your setup exceeded at Number Of Philosophers.\n");
		printf("Philo will now run at the limit of: %d\n"RESET, PHILOS_LIMIT);
	}
	if (table->timeto_die < 6e4
		|| table->timeto_eat < 6e4
		|| table->timeto_sleep < 6e4)
		error_manager("Time must be at least 60ms.");
	if (table->total_meals == 0)
		error_manager("Total meals must be greater then zero.");
}
