/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.table_philo_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:52 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 18:33:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Set the chopsticks for the philosopher, based on philo's id.
 * If the id is even, the first chopstick will be the one in the position of
 * the philosopher, and the second chopstick will be the next one. If the id
 * is odd, the first chopstick will be the next one, and the second chopstick
 * will be the one in the position of the philosopher.
 * @param philo The philosopher
 * @param chopsticks The chopsticks
 * @param philo_pos The position of the philosopher
 * @return void
 */
void	set_chopsticks(t_philo *philo, t_chops *chopsticks, int philo_pos)
{
	if (philo->id % 2 == 0)
	{
		philo->first_chops = &chopsticks[philo_pos];
		philo->second_chops = &chopsticks[(philo_pos + 1)
			% philo->table->set.total_philos];
	}
	else
	{
		philo->first_chops = &chopsticks[(philo_pos + 1)
			% philo->table->set.total_philos];
		philo->second_chops = &chopsticks[philo_pos];
	}
}

/**
 * @brief Initialize the philosophers. It sets the id, the meals, the full
 * status, the table, the mutex and the chopsticks. Also, initializes the
 * mutexes for `philo_mtx`, and sets the chopsticks for each philosopher.
 * @param table The table structure
 * @return void
 */
void	philo_init_runner(t_table *table)
{
	int		idx;
	t_philo	*philo;

	idx = -1;
	while (++idx < table->set.total_philos)
	{
		philo = table->philos + idx;
		philo->id = idx + 1;
		philo->got_meals = 0;
		philo->full = false;
		philo->table = table;
		safe_mutex_handler(&philo->philo_mtx, INIT);
		set_chopsticks(philo, table->chopsticks, idx);
	}
}

/**
 * @brief Allocate memory for the table structure
 * @param table The table structure
 * @return The table structure with the memory allocated
 */
t_table	*table_alloc(t_table *table)
{
	table->philos = ft_safe_malloc(sizeof(t_philo)
			* table->set.total_philos);
	table->chopsticks = ft_safe_malloc(sizeof(t_chops)
			* table->set.total_philos);
	return (table);
}

/**
 * @brief Initialize the table structure. It sets the mutexes and the
 * chopsticks. Also, initilizes the mutexes for `chopsticks`, `table_mtx`
 * and `printer_mtx`.
 * @param table The table structure
 * @return void
 */
void	table_init(t_table *table)
{
	int	idx;

	idx = -1;
	table->all_threads_ready_togo = false;
	table->this_is_the_end = false;
	table->start_time = 0;
	table->threads_running_counter = 0;
	table_alloc(table);
	safe_mutex_handler(&table->table_mtx, INIT);
	safe_mutex_handler(&table->printer_mtx, INIT);
	while (++idx < table->set.total_philos)
	{
		safe_mutex_handler(&table->chopsticks[idx].chops_mtx, INIT);
		table->chopsticks[idx].chops_id = idx;
	}
	philo_init_runner(table);
}
