/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.dinner_routines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 16:19:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	let_philo_eat_routine(t_philo *philo)
{
	safe_mutex_handler(&philo->first_chops->chops_mtx, LOCK);
	printer_with_mutex(GOT_1ST_CHOPSTICK, philo, false);
	safe_mutex_handler(&philo->second_chops->chops_mtx, LOCK);
	printer_with_mutex(GOT_2ND_CHOPSTICK, philo, false);
	
	set_long(philo->philo_mtx, &philo->time_of_last_meal, ft_gettime(MILISSECOND));
	philo->got_meals++;
	printer_with_mutex(EATING, philo, false);
	precise_usleep(philo->table->set->time_to_eat, philo->table);
	if (philo->table->set->total_meals > 0
		&& philo->got_meals == philo->table->set->total_meals)
		set_bool(philo->philo_mtx, &philo->full, true);
	safe_mutex_handler(&philo->first_chops->chops_mtx, UNLOCK);
	safe_mutex_handler(&philo->second_chops->chops_mtx, UNLOCK);
}

