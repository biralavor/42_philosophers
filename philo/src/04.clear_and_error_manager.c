/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.clear_and_error_manager.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:33:35 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/26 22:11:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Print an error message and exit the program
 * @param error_msg The error message to be printed
 */
void	error_manager(const char *error_msg)
{
	write(STDERR_FILENO, RED, ft_strlen(RED));
	write(STDERR_FILENO, "<< Error >>\n", 13);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, RESET, ft_strlen(RESET));
	write(STDERR_FILENO, "\n", 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief Free the table structure, destroy the mutexes and free the memory
 * @param table The table structure 
 * @return void
 */
void	free_table(t_table *table)
{
	int		idx;
	t_philo	*philo;

	idx = -1;
	while (++idx < table->total_philos)
	{
		philo = table->philos + idx;
		safe_mutex_handler(&philo->philo_mtx, DESTROY);
	}
	safe_mutex_handler(&table->table_mtx, DESTROY);
	safe_mutex_handler(&table->printer_mtx, DESTROY);
	free(table->chopsticks);
	free(table->philos);
}
