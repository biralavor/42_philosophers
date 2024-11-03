/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:57:26 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/03 10:44:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_gettime(t_time_code timecode)
{
	struct timeval	actual_time;
	
	if (gettimeofday(&actual_time, NULL))
		error_manager("Unable to get actual time.\n");
	if (SECOND == timecode)
		return (actual_time.tv_sec + (actual_time.tv_usec / 1e6));
	else if (MILLISECOND == timecode)
		return ((actual_time.tv_sec * 1e3) + (actual_time.tv_usec / 1e3));
	else if (MICROSECOND == timecode)
		return ((actual_time.tv_sec * 1e6) + (actual_time.tv_usec));
	else
		error_manager("Invalid time code.\n \
			Usage: SECOND, MILLISECOND or MICROSECOND\n");
	return (1985);
}
