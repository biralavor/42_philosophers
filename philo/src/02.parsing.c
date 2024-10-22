/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/22 17:47:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table_alloc(t_table *table)
{
	table = malloc(sizeof(t_table));
	table->setup = malloc(sizeof(t_setup));
	table->mtx_philo = malloc(sizeof(pthread_mutex_t));
	return (table);
}

void	table_parsing(t_table *table, char **av)
{
	table = table_alloc(table);
	table->setup->total_philos = ft_atoi_long_int(av[1]);
	table = table_holder(table, false);
}

bool	arguments_validation(int ac, char **av)
{
	(void)av;
	if (ac < 2)
	{
		printf("This version needs at least a number of philosophers\n");
		return (false);
	}
	return (true);
}
