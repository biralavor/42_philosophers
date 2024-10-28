/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.mutex_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:16:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/28 15:45:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_mutex_handler(int status, int opcode)
{
	if (0 == status)
		return ;
	else if (EINVAL == status && (INIT == opcode))
		error_manager("The value specified at attribute is invalid.\n");
	else if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode
		|| DESTROY == opcode))
		error_manager("Invalid settings in attribute.\n");
	else if (EAGAIN == status)
		error_manager("Insufficient resources to create another thread.\n");
	else if (EDEADLK == status)
		error_manager("A deadlock condition was detected.\n");
	else if (EPERM == status)
		error_manager("The current thread does not hold a lock on mutex.\n");
	else if (ENOMEM == status)
		error_manager("The process cannot allocate enought memory \
			to create another mutex.\n");
	else if (EBUSY == status)
		error_manager("The mutex is already locked.\n");
}

void	safe_mutex_handler(t_table *table, t_mtx_opcode opcode)
{
	if (INIT == opcode)
		error_mutex_handler(pthread_mutex_init(table->ph_mtx, NULL), opcode);
	else if (LOCK == opcode)
		error_mutex_handler(pthread_mutex_lock(table->ph_mtx), opcode);
	else if (UNLOCK == opcode)
		error_mutex_handler(pthread_mutex_unlock(table->ph_mtx), opcode);
	else if (DESTROY == opcode)
		error_mutex_handler(pthread_mutex_destroy(table->ph_mtx), opcode);
	else
	{
		write(STDERR_FILENO, RED, ft_strlen(RED));
		write(STDERR_FILENO, "Invalid opcode at safe mutex handler ", 38);
		error_manager("Usage: INIT, LOCK, UNLOCK or DESTROY\n");
	}
}