/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.dinner_routines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/09 20:03:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function is the main routine for the philosopher to eat.
 * It locks the mutex of the first chopstick, then the second one. After that,
 * it sets the time of the last meal, and increases the number of meals.
 * If the total number of meals is reached, it sets the philosopher as full.
 * Finally, it unlocks the mutex of the chopsticks.
 * @param philo The philosopher structure
 * @return void
 */
void	let_philo_eat_routine(t_philo *philo)
{
	safe_mutex_handler(&philo->first_chops->chops_mtx, LOCK);
	printer_manager(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	safe_mutex_handler(&philo->second_chops->chops_mtx, LOCK);
	printer_manager(GOT_2ND_CHOPSTICK, philo, DEBUG_MODE);
	philo->got_meals++;
	set_long(&philo->philo_mtx, &philo->time_of_last_meal,
		ft_gettime(MILLISECOND));
	printer_manager(EATING, philo, DEBUG_MODE);
	if (philo->table->set.total_meals > 0
		&& philo->got_meals == philo->table->set.total_meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
	precise_usleep(philo->table->set.time_to_eat, philo->table);
	safe_mutex_handler(&philo->first_chops->chops_mtx, UNLOCK);
	safe_mutex_handler(&philo->second_chops->chops_mtx, UNLOCK);
}

/**
 * @brief This function is the main routine for the philosopher to sleep.
 * It prints the status of the philosopher, and sleeps for the time to sleep.
 * @param philo The philosopher structure
 * @return void
 */
void	let_philo_sleep_routine(t_philo *philo)
{
	printer_manager(SLEEPING, philo, DEBUG_MODE);
	precise_usleep(philo->table->set.time_to_sleep, philo->table);
}

/**
 * @brief This function is the main routine for the philosopher to think.
 * It prints the status of the philosopher, and if the total number of
 * philosophers is even, it returns. Otherwise, it calculates the time
 * to think, and sleeps for that time.
 * @param philo The philosopher structure
 * @param before_spinlock A boolean that indicates if the function
 * is called before the spinlock.
 * @return void
 */
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

/**
 * @brief This is the function if there is only one philosopher. It sets the
 * time of the last meal, and increases the number of threads running.
 * After that, it prints the status of the philosopher, and sleeps
 * for 200 microseconds.
 * @param data The philosopher structure
 * @return void
 */
void	*lonely_philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	holdon_until_all_threads(philo->table);
	set_long(&philo->philo_mtx,
		&philo->time_of_last_meal, ft_gettime(MILLISECOND));
	increase_long(&philo->table->table_mtx,
		&philo->table->threads_running_counter);
	printer_manager(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	while (!this_is_the_end_of_dinner(philo->table))
		precise_usleep(200, philo->table);
	return (NULL);
}
