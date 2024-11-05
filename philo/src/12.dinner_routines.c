/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.dinner_routines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/05 11:12:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	let_philo_eat_routine(t_philo *philo)
{
	safe_mutex_handler(&philo->first_chops->chops_mtx, LOCK);
	printer_manager(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	safe_mutex_handler(&philo->second_chops->chops_mtx, LOCK);
	printer_manager(GOT_2ND_CHOPSTICK, philo, DEBUG_MODE);
	set_long(&philo->philo_mtx, &philo->time_of_last_meal,
		ft_gettime(MILLISECOND));
	philo->got_meals++;
	printer_manager(EATING, philo, DEBUG_MODE);
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
		printer_manager(THINKING, philo, DEBUG_MODE);
	if (philo->table->set.total_philos % 2 == 0)
		return ;
	else
	{
		think_time = (philo->table->set.time_to_eat * 2)
			- philo->table->set.time_to_sleep;
		if (think_time < 0)
			think_time = 0;
		precise_usleep(think_time * 0.5, philo->table);
	}
}

void	let_philo_sleep_routine(t_philo *philo)
{
	printer_manager(SLEEPING, philo, DEBUG_MODE);
	precise_usleep(philo->table->set.time_to_sleep, philo->table);
}

void	*lonely_philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	semaphore_like_for_threads(philo->table);
	set_long(&philo->philo_mtx,
		&philo->time_of_last_meal, ft_gettime(MILLISECOND));
	increase_long(&philo->table->table_mtx,
		&philo->table->threads_running_counter);
	printer_manager(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	while (!this_is_the_end_of_dinner(philo->table))
		precise_usleep(200, philo->table);
	return (NULL);
}
