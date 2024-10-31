/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precise_usleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:34:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/31 18:48:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_elapsed_time_microsec(struct timeval start, struct timeval end)
{
	long result;

	result = end.tv_sec - start.tv_sec * 1000000L;
	result += end.tv_usec - start.tv_usec;
	return (result);
}

void	precise_usleep(long microsec, t_table *table)
{
	long	start;
	long	elapsed_time;
	long	remaining_time;

	start = ft_gettime(MICROSECOND);
	elapsed_time = 0;
	remaining_time = 0;
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
