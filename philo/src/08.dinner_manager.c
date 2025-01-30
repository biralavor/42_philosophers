/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.dinner_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:01:45 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/29 15:01:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function is the main function that manages the dinner. It
 * creates the threads for the philosophers, calls the monitor, and waits for
 * them to finish. It also sets the start time of the dinner. After creating
 * threads and running `dinner runner`, it sets that all threads are ready
 * to go. After an ending condition happend at `dinner runner`, threads and
 * the monitor are joined.
 * @param table The table structure
 * @return void
 */
void	dinner_manager(t_table *table)
{
	int	idx;

	idx = -1;
	if (table->total_meals == 0)
		return ;
	else if (table->total_philos == 1)
		safe_thread_handler(&table->philos[0].th_id,
			lonely_philo_routine, &table->philos[0], CREATE);
	else
	{
		while (++idx < table->total_philos)
			safe_thread_handler(&table->philos[idx].th_id,
				dinner_runner, &table->philos[idx], CREATE);
	}
	safe_thread_handler(&table->monitor_thread, monitor_runner, table, CREATE);
	table->start_time = ft_gettime(MILLISECOND);
	set_bool(&table->table_mtx, &table->all_threads_up, true);
	idx = -1;
	while (++idx < table->total_philos)
		safe_thread_handler(&table->philos[idx].th_id, NULL, NULL, JOIN);
	set_bool(&table->table_mtx, &table->this_is_the_end, true);
	safe_thread_handler(&table->monitor_thread, NULL, NULL, JOIN);
}

/**
 * @brief `dinner runner` sets a job for every created philosopher. It also
 * sets the start time of the dinner, and the boolean that indicates
 * that all threads are ready to go.
 * @param table The table structure
 * @return void
 */
void	*dinner_runner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	holdon_until_all_threads(philo->table);
	set_long(&philo->philo_mtx, &philo->timeof_lastmeal,
		ft_gettime(MILLISECOND));
	increase_long(&philo->table->table_mtx,
		&philo->table->running_threads_idx);
	unsync_this_philo(philo);
	while (!is_this_the_end(philo->table))
	{
		let_philo_eat_routine(philo);
		if (get_bool(&philo->table->table_mtx, &philo->table->philos->full))
			break ;
		printer_manager(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->timeto_sleep, philo->table);
		let_philo_think_routine(philo, false);
	}
	return (NULL);
}
