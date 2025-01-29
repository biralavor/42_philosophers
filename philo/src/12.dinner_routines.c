/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.dinner_routines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:23 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/29 16:07:04 by umeneses         ###   ########.fr       */
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
	// safe_mutex_handler(&philo->first_chops->chops_mtx, LOCK);
	// safe_mutex_handler(&philo->second_chops->chops_mtx, LOCK);
	pthread_mutex_lock(&philo->first_chops->chops_mtx);
	pthread_mutex_lock(&philo->second_chops->chops_mtx);
	printer_manager(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	printer_manager(GOT_2ND_CHOPSTICK, philo, DEBUG_MODE);
	set_long(&philo->philo_mtx, &philo->timeof_lastmeal,
		ft_gettime(MILLISECOND));
	philo->got_meals++;
	printer_manager(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->timeto_eat, philo->table);
	pthread_mutex_unlock(&philo->first_chops->chops_mtx);
	pthread_mutex_unlock(&philo->second_chops->chops_mtx);
	if (philo->table->total_meals > 0
		&& philo->got_meals == philo->table->total_meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
	// safe_mutex_handler(&philo->first_chops->chops_mtx, UNLOCK);
	// safe_mutex_handler(&philo->second_chops->chops_mtx, UNLOCK);
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
	precise_usleep(philo->table->timeto_sleep, philo->table);
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
	long	sleep_time;
	long	eat_time;

	if (!before_spinlock)
		printer_manager(THINKING, philo, DEBUG_MODE);
	if (philo->table->total_philos % 2 == 0)
		return ;
	eat_time = philo->table->timeto_eat;
	sleep_time = philo->table->timeto_sleep;
	think_time = (eat_time * 2) - sleep_time;
	if (think_time < 0)
		think_time = 0;
	precise_usleep(think_time * 0.5, philo->table);
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
		&philo->timeof_lastmeal, ft_gettime(MILLISECOND));
	increase_long(&philo->table->table_mtx,
		&philo->table->running_threads_idx);
	printer_manager(GOT_1ST_CHOPSTICK, philo, DEBUG_MODE);
	while (!is_this_the_end(philo->table))
		precise_usleep(200, philo->table);
	return (NULL);
}
