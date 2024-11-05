/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.dinner_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:01:45 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/05 07:13:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief: what if set.total_meals == -1?
 */
void	dinner_manager(t_table *table)
{
	int	idx;

	idx = -1;
	if (table->set.total_meals == 0)
		return ;
	else if (table->set.total_philos == 1)
		safe_thread_handler(&table->philos[0].th_id,
			lonely_philo_routine, &table->philos[0], CREATE);
	else
	{
		while (++idx < table->set.total_philos)
			safe_thread_handler(&table->philos[idx].th_id,
				dinner_runner, &table->philos[idx], CREATE);
	}
	safe_thread_handler(&table->monitor_thread, monitor_runner, table, CREATE);
	table->start_time = ft_gettime(MILLISECOND);
	set_bool(&table->table_mtx, &table->all_threads_ready_togo, true);
	idx = -1;
	while (++idx < table->set.total_philos)
		safe_thread_handler(&table->philos[idx].th_id, NULL, NULL, JOIN);
	set_bool(&table->table_mtx, &table->this_is_the_end, true);
	safe_thread_handler(&table->monitor_thread, NULL, NULL, JOIN);
}

void	*dinner_runner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	semaphore_like_for_threads(philo->table);
	set_long(&philo->philo_mtx, &philo->time_of_last_meal,
		ft_gettime(MILLISECOND));
	increase_long(&philo->table->table_mtx,
		&philo->table->threads_running_counter);
	philos_in_async_mode(philo);
	while (!this_is_the_end_of_dinner(philo->table))
	{
		if (get_bool(&philo->table->table_mtx, &philo->table->philos->full))
			break ;
		let_philo_eat_routine(philo);
		let_philo_sleep_routine(philo);
		let_philo_think_routine(philo, false);
	}
	return (NULL);
}
