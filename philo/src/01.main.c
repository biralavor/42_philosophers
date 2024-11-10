/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/10 14:29:36 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Check if the arguments are valid
 * @param ac Number of arguments
 * @param av Arguments
 * @return `true` if the arguments passed in all verifications,
 * otherwise `false`.
 */
bool	arguments_validation_manager(int ac, char **av)
{
	if (arguments_amount(ac))
	{
		if (argument_number_validation(av))
		{
			if (is_valid_length_number(av) && is_number_under_intmax(ac, av))
				return (true);
			error_manager("Arguments must be under or equal INT MAX.\n");
		}
		error_manager("Arguments must be a number and a positive number.\n");
	}
	return (false);
}

/**
 * @brief Main function of the program
 * @param ac Number of arguments
 * @param av Arguments
 * @return `EXIT_FAILURE`, if arguments validation fails,
 * otherwise the program will run.
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
