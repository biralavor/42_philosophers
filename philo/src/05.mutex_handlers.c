/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.mutex_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:16:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/26 13:35:22 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Print an error message based on the `status` and the `opcode`
 * @param status The status of the mutex operation, defined by `errno.h` codes
 * @param opcode The operation code called
 * @return void
 */
void	mutex_error_handler(int status, int opcode)
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

/**
 * @brief Handle the mutex operations,
 * in a safe mode calling the `error mutex handler` simultaneously
 * @param mutex The mutex to be handled
 * @param opcode The operation code called
 */
void	safe_mutex_handler(pthread_mutex_t *mutex, t_mtx_opcode opcode)
{
	if (INIT == opcode)
		mutex_error_handler(pthread_mutex_init(mutex, NULL), opcode);
	else if (LOCK == opcode)
		mutex_error_handler(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		mutex_error_handler(pthread_mutex_unlock(mutex), opcode);
	else if (DESTROY == opcode)
		mutex_error_handler(pthread_mutex_destroy(mutex), opcode);
	else
	{
		write(STDERR_FILENO, RED, ft_strlen(RED));
		write(STDERR_FILENO, "Invalid opcode at safe mutex handler ", 38);
		error_manager("Usage: INIT, LOCK, UNLOCK or DESTROY\n");
	}
}
