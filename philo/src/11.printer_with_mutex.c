/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.printer_with_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:12:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 19:07:29 by umeneses         ###   ########.fr       */
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
	safe_mutex_handler(&philo->table->printer_mtx, LOCK);
	if (debug == 1 && !this_is_the_end_of_dinner(philo->table))
		printer_with_mutex_chopsticks(status, philo, elapsed);
	else if (debug == 2 && !this_is_the_end_of_dinner(philo->table))
		printer_with_mutex_debug(status, philo, elapsed);
	else if (!this_is_the_end_of_dinner(philo->table))
		printer_with_mutex_classic(status, philo, elapsed);
	safe_mutex_handler(&philo->table->printer_mtx, UNLOCK);
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
	if (GOT_1ST_CHOPSTICK == status || GOT_2ND_CHOPSTICK == status)
		printf(YELLOW"%-10ld"RESET" %d"YELLOW" has taken"
			" a fork\n", elapsed, philo->id);
	else if (EATING == status)
		printf(GREEN"%-10ld"RESET" %d"GREEN" is eating\n",
			elapsed, philo->id);
	else if (SLEEPING == status)
		printf(BLUE"%-10ld"RESET" %d"BLUE" is sleeping\n",
			elapsed, philo->id);
	else if (THINKING == status)
		printf(PURPLE"%-10ld"RESET" %d"PURPLE" is thinking\n",
			elapsed, philo->id);
	else if (DEAD == status)
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
	if (GOT_1ST_CHOPSTICK == status || GOT_2ND_CHOPSTICK == status)
		printf(YELLOW"%10ld"RESET" philo %d"YELLOW" has taken"
			" a chopstick\n", elapsed, philo->id);
	else if (EATING == status)
		printf(GREEN"%10ld"RESET" philo %d"GREEN" is eating\n",
			elapsed, philo->id);
	else if (SLEEPING == status)
		printf(BLUE"%10ld"RESET" philo %d"BLUE" is sleeping\n",
			elapsed, philo->id);
	else if (THINKING == status)
		printf(PURPLE"%10ld"RESET" philo %d"PURPLE" is thinking\n",
			elapsed, philo->id);
	else if (DEAD == status)
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
	if (GOT_1ST_CHOPSTICK == status)
		printf(YELLOW"%10ld"RESET" philo %d"YELLOW" has taken"
			" the 1st chopstick 1️⃣ 🥢\tchopstick id: %d\n",
			elapsed, philo->id, philo->first_chops->chops_id);
	else if (GOT_2ND_CHOPSTICK == status)
		printf(YELLOW"%10ld"RESET" philo %d"YELLOW" has taken"
			" the 2nd chopstick 2️⃣ 🥢\tchopstick id: %d\n",
			elapsed, philo->id, philo->second_chops->chops_id);
	else if (EATING == status)
		printf(GREEN"%10ld"RESET" philo %d"GREEN" is eating 🍕"
			" \t\t\tmeals number: %ld\n", elapsed, philo->id, philo->got_meals);
	else if (SLEEPING == status)
		printf(BLUE"%10ld"RESET" philo %d"BLUE" is sleeping 😴\n",
			elapsed, philo->id);
	else if (THINKING == status)
		printf(PURPLE"%10ld"RESET" philo %d"PURPLE" is thinking 🤔\n",
			elapsed, philo->id);
	else if (DEAD == status)
		printf(RED"%10ld philo %d died ❌❌❌ 💀 💀 💀\n"RESET,
			elapsed, philo->id);
}
