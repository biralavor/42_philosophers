/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.dinner_routines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/04 18:10:30 by umeneses         ###   ########.fr       */
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
				set_bool(&table->table_mtx, &table->this_is_the_end, true);
				printer_with_mutex(DEAD, table->philos + idx, DEBUG_MODE);
			}
		}
	}
	return (NULL);
}

bool	is_philo_dead_manager(t_philo *philo)
{
	long	time_to_die;
	long	elapsed;

	if (get_bool(&philo->philo_mtx, &philo->full))
		return (false);
	elapsed = ft_gettime(MILLISECOND) - get_long(&philo->philo_mtx,
		&philo->time_of_last_meal);
	time_to_die = philo->table->set.time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

void	let_philo_eat_routine(t_philo *philo)
{
	safe_mutex_handler(&philo->first_chops->chops_mtx, LOCK);
	printer_with_mutex(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	safe_mutex_handler(&philo->second_chops->chops_mtx, LOCK);
	printer_with_mutex(GOT_2ND_CHOPSTICK, philo, DEBUG_MODE);
	set_long(&philo->philo_mtx, &philo->time_of_last_meal,
		ft_gettime(MILLISECOND));
	philo->got_meals++;
	printer_with_mutex(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->set.time_to_eat, philo->table);
	if (philo->table->set.total_meals > 0
		&& philo->got_meals == philo->table->set.total_meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
	safe_mutex_handler(&philo->first_chops->chops_mtx, UNLOCK);
	safe_mutex_handler(&philo->second_chops->chops_mtx, UNLOCK);
}

void	let_philo_think_routine(t_philo *philo, bool before_spinlock)
{
	long	think_time;

	think_time = 0;
	if (!before_spinlock)
		printer_with_mutex(THINKING, philo, DEBUG_MODE);
	if (philo->table->set.total_philos % 2 == 0)
		return ;
	else
	{	
		think_time = philo->table->set.time_to_eat
			* 2 - philo->table->set.time_to_sleep;
		if (think_time < 0)
			think_time = 0;
		precise_usleep(think_time * 0.5, philo->table);
	}
}

void	let_philo_sleep_routine(t_philo *philo)
{
	printer_with_mutex(SLEEPING, philo, DEBUG_MODE);
	precise_usleep(philo->table->set.time_to_sleep, philo->table);
}

void	*lonely_philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	semaphore_like_for_threads(philo->table);
	set_long(&philo->philo_mtx, &philo->time_of_last_meal, ft_gettime(MILLISECOND));
	increase_long(&philo->table->table_mtx, &philo->table->threads_running_counter);
	printer_with_mutex(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	while(!this_is_the_end_of_dinner(philo->table))
		usleep(200);
	return (NULL);
}
