/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:57:26 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/29 19:11:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_gettime(t_time_code timecode)
{
	struct timeval	t_val;
	
	if (gettimeofday(&t_val, NULL) == -1)
		error_manager("Unable to get actual time.\n");
	if (SECOND == timecode)
		return (t_val.tv_sec + (t_val.tv_usec / 1e6));
	else if (MILISSECOND == timecode)
		return ((t_val.tv_usec * 1e3) + (t_val.tv_usec / 1e3));
	else if (MICROSECOND == timecode)
		return ((t_val.tv_sec * 1e6) + (t_val.tv_usec));
	else
		error_manager("Invalid time code.\n \
			Usage: SECOND, MILISSECOND or MICROSECOND\n");
	return (1985);
}
