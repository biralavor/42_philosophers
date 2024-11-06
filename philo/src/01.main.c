/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 15:48:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Main function of the program
 * @param ac Number of arguments
 * @param av Arguments
 * @return int EXIT_SUCCESS or EXIT_FAILURE
 */
int	main(int ac, char **av)
{
	t_table	table;

	if (!arguments_validation_manager(ac, av))
		return (EXIT_FAILURE);
	table_parsing(&table, av);
	table_init(&table);
	dinner_manager(&table);
	table_free(&table);
	return (EXIT_SUCCESS);
}
