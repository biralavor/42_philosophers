/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.printer_with_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:12:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/03 10:10:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printer_with_mutex(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = ft_gettime(MILLISECOND) - philo->table->start_time;
	if (philo->full)
		return ;
	safe_mutex_handler(&philo->table->printer_mtx, LOCK);
	if (debug)
		printer_with_mutex_debug(status, philo, elapsed);
	else if (!this_is_the_end_of_dinner(philo->table))
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
			printf(RED"%10ld"RESET" philo %d"RED" died\n",
				elapsed, philo->id);
	}
	safe_mutex_handler(&philo->table->printer_mtx, UNLOCK);
}

void	printer_with_mutex_debug(t_philo_status status, t_philo *philo, long elapsed)
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
		printf(RED"%10ld"RESET" philo %d"RED" died ☠ ☠ ☠\n",
			elapsed, philo->id);
}
