/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/27 21:41:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table_alloc(t_table *table, char **av)
{
	table = malloc(sizeof(t_table));
	table->set = malloc(sizeof(t_set));
	table->philo = malloc(sizeof(t_philo) * ft_atoi_long_int(av[1]));
	table->philo->th_id = malloc(sizeof(pthread_t) * ft_atoi_long_int(av[1]));
	table->ph_mtx = malloc(sizeof(pthread_mutex_t));
	return (table);
}

/**
 * @todo: free table if error_manager is called
 */
void	table_parsing(t_table *table, char **av)
{
	table = table_alloc(table, av);
	table->set->total_philos = ft_atoi_long_int(av[1]);
	table->set->time_to_die = ft_atoi_long_int(av[2]) * 1e3;
	table->set->time_to_eat = ft_atoi_long_int(av[3]) * 1e3;
	table->set->time_to_sleep = ft_atoi_long_int(av[4]) * 1e3;
	if (av[5])
		table->set->total_meals = ft_atoi_long_int(av[5]);
	else
		table->set->total_meals = -1;
	table = table_holder(table, false);
	table_mutex_init(table);
	if (table->set->time_to_die < 6e4
		|| table->set->time_to_eat < 6e4
		|| table->set->time_to_sleep < 6e4)
	{
		error_manager("Error.\nTime must be at least 60ms.\n");
	}
}
