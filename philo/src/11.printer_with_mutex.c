/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.printer_with_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:12:00 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/29 16:42:07 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function manages the printer. It calls the printer with mutex
 * functions, and locks the printer mutex to avoid any other philosopher
 * access the printer.
 * @param status The status of the philosopher
 * @param philo The philosopher structure
 * @param debug The debug mode
 * @return void
 */
void	printer_manager(t_philo_status status, t_philo *philo, int debug)
{
	long	elapsed;

	elapsed = ft_gettime(MILLISECOND) - philo->table->start_time;
	if (philo->full)
		return ;
	pthread_mutex_lock(&philo->table->printer_mtx);
	if (debug == 1)
		printer_with_mutex_chopsticks(status, philo, elapsed);
	else if (debug == 2)
		printer_with_mutex_debug(status, philo, elapsed);
	else
		printer_with_mutex_classic(status, philo, elapsed);
	pthread_mutex_unlock(&philo->table->printer_mtx);
}

/**
 * @brief This function prints the status of the philosopher in a classic way.
 * @param status The status of the philosopher
 * @param philo The philosopher structure
 * @param elapsed The elapsed time since the start of the dinner
 * @return void
 */
void	printer_with_mutex_classic(t_philo_status status,
	t_philo *philo, long elapsed)
{
	if ((GOT_1ST_CHOPSTICK == status || GOT_2ND_CHOPSTICK == status)
		&& !is_this_the_end(philo->table))
		printf(YELLOW"%-10ld"RESET" %d"YELLOW" has taken"
			" a fork\n", elapsed, philo->id);
	else if (EATING == status && !is_this_the_end(philo->table))
		printf(GREEN"%-10ld"RESET" %d"GREEN" is eating\n",
			elapsed, philo->id);
	else if (SLEEPING == status && !is_this_the_end(philo->table))
		printf(BLUE"%-10ld"RESET" %d"BLUE" is sleeping\n",
			elapsed, philo->id);
	else if (THINKING == status && !is_this_the_end(philo->table))
		printf(PURPLE"%-10ld"RESET" %d"PURPLE" is thinking\n",
			elapsed, philo->id);
	else if (DEAD == status && !is_this_the_end(philo->table))
		printf(RED"%-10ld %d died\n"RESET,
			elapsed, philo->id);
}

/**
 * @brief This function prints the status of the philosopher, replacing `forks`
 * with `chopsticks`, which I think is more reasonable.
 * @param status The status of the philosopher
 * @param philo The philosopher structure
 * @param elapsed The elapsed time since the start of the dinner
 * @return void
 */
void	printer_with_mutex_chopsticks(t_philo_status status,
	t_philo *philo, long elapsed)
{
	if ((GOT_1ST_CHOPSTICK == status || GOT_2ND_CHOPSTICK == status)
		&& !is_this_the_end(philo->table))
		printf(YELLOW"%10ld"RESET" philo %d"YELLOW" has taken"
			" a chopstick\n", elapsed, philo->id);
	else if (EATING == status
		&& !is_this_the_end(philo->table))
		printf(GREEN"%10ld"RESET" philo %d"GREEN" is eating\n",
			elapsed, philo->id);
	else if (SLEEPING == status
		&& !is_this_the_end(philo->table))
		printf(BLUE"%10ld"RESET" philo %d"BLUE" is sleeping\n",
			elapsed, philo->id);
	else if (THINKING == status
		&& !is_this_the_end(philo->table))
		printf(PURPLE"%10ld"RESET" philo %d"PURPLE" is thinking\n",
			elapsed, philo->id);
	else if (DEAD == status
		&& !is_this_the_end(philo->table))
		printf(RED"%10ld philo %d died\n"RESET,
			elapsed, philo->id);
}

/**
 * @brief This function prints the status of the philosopher in a debug way.
 * It shows the chopsticks id, and the actual number of meals.
 * @param status The status of the philosopher
 * @param philo The philosopher structure
 * @param elapsed The elapsed time since the start of the dinner
 * @return void
 */
void	printer_with_mutex_debug(t_philo_status status,
	t_philo *philo, long elapsed)
{
	if (GOT_1ST_CHOPSTICK == status
		&& !is_this_the_end(philo->table))
		printf(YELLOW"%10ld"RESET" philo %d"YELLOW" has taken"
			"  1️⃣  chopstick 🥢\tchopstick id: %d\n",
			elapsed, philo->id, philo->first_chops->chops_id);
	else if (GOT_2ND_CHOPSTICK == status
		&& !is_this_the_end(philo->table))
		printf(YELLOW"%10ld"RESET" philo %d"YELLOW" has taken"
			"  2️⃣  chopstick 🥢\tchopstick id: %d\n",
			elapsed, philo->id, philo->second_chops->chops_id);
	else if (EATING == status
		&& !is_this_the_end(philo->table))
		printf(GREEN"%10ld"RESET" philo %d"GREEN" is eating 🍕"
			"\t\t\tmeals number: %ld\n", elapsed, philo->id, philo->got_meals);
	else if (SLEEPING == status
		&& !is_this_the_end(philo->table))
		printf(BLUE"%10ld"RESET" philo %d"BLUE" is sleeping 😴\n",
			elapsed, philo->id);
	else if (THINKING == status
		&& !is_this_the_end(philo->table))
		printf(PURPLE"%10ld"RESET" philo %d"PURPLE" is thinking 🤔\n",
			elapsed, philo->id);
	else if (DEAD == status
		&& !is_this_the_end(philo->table))
		printf(RED"%10ld philo %d died ❌❌❌ 💀💀💀\n"RESET, elapsed, philo->id);
}
