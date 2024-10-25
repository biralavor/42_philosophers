/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/25 20:24:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table_alloc(t_table *table, char **av)
{
	table = malloc(sizeof(t_table));
	table->set = malloc(sizeof(t_set));
	table->philo = malloc(sizeof(t_philo) * ft_atoi_long_int(av[1]));
	table->philo->th_id = malloc(sizeof(pthread_t)  * ft_atoi_long_int(av[1]));
	table->ph_mtx = malloc(sizeof(pthread_mutex_t));
	return (table);
}

void	table_parsing(t_table *table, char **av)
{
	table = table_alloc(table, av);
	table->set->total_philos = ft_atoi_long_int(av[1]);
	table = table_holder(table, false);
}
