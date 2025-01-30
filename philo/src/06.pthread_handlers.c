/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.pthread_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:16:28 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/26 22:11:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Print an error message based on the `status` and the `opcode`
 * @param status The status of the pthread operation, defined by `errno.h` codes
 * @param opcode The operation code called
 * @return void
 */
void	pthread_error_handler(int status, int opcode)
{
	if (0 == status)
		return ;
	else if (EAGAIN == status)
		error_manager("Insufficient resources to create another thread.");
	else if (EPERM == status)
		error_manager("The caller does not have"
			"the appropriate permission.");
	else if (EINVAL == status && (CREATE == opcode))
		error_manager("The value specified at attribute is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_manager("The value specified by thread is not joinable.");
	else if (ESRCH == status)
		error_manager("No thread could be found corresponding to that"
			" specified by the given thread ID.");
	else if (EDEADLK == status)
		error_manager("A deadlock was detected or the value of thread"
			" specifies the calling thread.");
}

/**
 * @brief Handle the pthread operations,
 * in a safe mode calling the `error pthread handler` simultaneously
 * @param th_id The thread id to be handled
 * @param func_ptr The function pointer to be called
 * @param data The data to be passed to the function
 * @param opcode The operation code called
 * @return void
 */
void	safe_thread_handler(pthread_t *th_id, void *(*func_ptr)(void *),
			void *data, t_mtx_opcode opcode)
{
	if (CREATE == opcode)
		pthread_error_handler(pthread_create(th_id, NULL,
				func_ptr, data), opcode);
	else if (JOIN == opcode)
		pthread_error_handler(pthread_join(*th_id, data), opcode);
	else if (DETACH == opcode)
		pthread_error_handler(pthread_detach(*th_id), opcode);
	else
	{
		write(STDERR_FILENO, RED, ft_strlen(RED));
		write(STDERR_FILENO, "Invalid opcode at safe thread handler ", 39);
		error_manager("Usage: CREATE, JOIN or DETACH");
	}
}
