/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/04 18:33:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main (int ac, char **av)
{
	t_table	table;

	if (!arguments_validation_manager(ac, av))
		exit(EXIT_FAILURE);
	table_parsing(&table, av);
	table_init(&table);
	dinner_manager(&table);
	table_free(&table);
	exit(EXIT_SUCCESS);
}
