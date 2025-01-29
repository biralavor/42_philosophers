/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:57:56 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/29 11:18:47 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function is the main routine for the monitor. The goal here
 * is to really monitoring the philosophers, and check if someone is dead.
 * If a philosopher is dead, it prints the status of the philosopher, and
 * sets the boolean that indicates the end of dinner.
 * @param data The table structure
 * @return void*
 */
void	*monitor_runner(void *data)
{
	int		idx;
	t_table	*table;

	table = (t_table *)data;
	while (!all_threads_are_running(&table->table_mtx,
			&table->running_threads_idx, table->total_philos))
		;
	while (!is_this_the_end(table))
	{
		idx = -1;
		while (++idx < table->total_philos
			&& !is_this_the_end(table))
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

/**
 * @brief This function checks if the philosopher is dead. It calculates the
 * elapsed time since the last meal, and if it is greater than the time to die,
 * it prints the status of the philosopher, and sets the boolean that indicates
 * the end of dinner.
 * @param philo The philosopher structure
 * @return true If the philosopher is dead
 * @return false If the philosopher is not dead
 */
bool	is_philo_dead_manager(t_philo *philo)
{
	long	timeto_die;
	long	elapsed;

	if (get_bool(&philo->philo_mtx, &philo->full))
		return (false);
	elapsed = ft_gettime(MILLISECOND) - get_long(&philo->philo_mtx,
			&philo->timeof_lastmeal);
	timeto_die = philo->table->timeto_die / 1e3;
	if (elapsed > timeto_die)
		return (true);
	return (false);
}
