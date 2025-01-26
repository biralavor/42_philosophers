/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precise_usleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:34:23 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/26 18:20:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function sleeps for a precise amount of time in microseconds.
 * It calculates the elapsed time, and the remaining time to sleep.
 * If the remaining time is greater than 1e3, it sleeps for half of the
 * remaining time. Otherwise, it sleeps until the time is reached.
 * @param microsec The time to sleep in microseconds
 * @param table The table structure
 * @return void
 */
void	precise_usleep(long microsec, t_table *table)
{
	long	start;
	long	elapsed_time;
	long	remaining_time;

	start = ft_gettime(MICROSECOND);
	while (ft_gettime(MICROSECOND) - start < microsec)
	{
		if (this_is_the_end_of_dinner(table))
			break ;
		elapsed_time = ft_gettime(MICROSECOND) - start;
		remaining_time = microsec - elapsed_time;
		if (remaining_time > 1e3)
			usleep(remaining_time / 2);
		else
		{
			while (ft_gettime(MICROSECOND) - start < microsec)
				;
		}
	}
}
