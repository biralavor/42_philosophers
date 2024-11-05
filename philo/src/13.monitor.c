/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:57:56 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/05 10:59:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_runner(void *data)
{
	int		idx;
	t_table	*table;

	idx = 0;
	table = (t_table *)data;
	while (!all_threads_are_running(&table->table_mtx,
			&table->threads_running_counter, table->set.total_philos))
		;
	while (!this_is_the_end_of_dinner(table))
	{
		idx = -1;
		while (++idx < table->set.total_philos
			&& !this_is_the_end_of_dinner(table))
		{
			if (is_philo_dead_manager(table->philos + idx))
			{
				printer_manager(DEAD, table->philos + idx, DEBUG_MODE);
				set_bool(&table->table_mtx, &table->this_is_the_end, true);
			}
		}
	}
	return (NULL);
}

bool	is_philo_dead_manager(t_philo *philo)
{
	long	time_to_die;
	long	current;
	long	last_meal;

	if (get_bool(&philo->philo_mtx, &philo->full))
		return (false);
	current = ft_gettime(MILLISECOND);
	last_meal = get_long(&philo->philo_mtx, &philo->time_of_last_meal);
	time_to_die = philo->table->set.time_to_die / 1e3;
	if (current - last_meal > time_to_die)
		return (true);
	return (false);
}
