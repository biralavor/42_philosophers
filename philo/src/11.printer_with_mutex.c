/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.printer_with_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:12:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 13:36:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printer_with_mutex(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = ft_gettime(MILISSECOND) - philo->table->start_time;
	if (philo->full)
		return ;
	safe_mutex_handler(philo->table->printer_mtx, LOCK);
	if (debug)
		return ; // printer_with_mutex_debug(status, philo, elapsed);
	else if (!this_is_the_end_of_dinner(philo->table))
	{	
		if (GOT_1ST_CHOPSTICK == status || GOT_2ND_CHOPSTICK == status)
			printf(YELLOW"%-6ld"RESET" philo %d has taken a chopstick\n",
				elapsed, philo->id);
		else if (EATING == status)
			printf(GREEN"%-6ld"RESET" philo %d is eating\n",
				elapsed, philo->id);
		else if (SLEEPING == status)
			printf(YELLOW"%-6ld"RESET" philo %d is sleeping\n",
				elapsed, philo->id);
		else if (THINKING == status)
			printf(YELLOW"%-6ld"RESET" philo %d is thinking\n",
				elapsed, philo->id);
		else if (DEAD == status)
			printf(RED"%-6ld"RESET" philo %d is dead\n",
				elapsed, philo->id);
	}
	safe_mutex_handler(philo->table->printer_mtx, UNLOCK);
}

void	printer_with_mutex_debug(t_philo_status status, t_philo *philo, bool debbug)
{
	(void)status;
	(void)philo;
	(void)debbug;
}
