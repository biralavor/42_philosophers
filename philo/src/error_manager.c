/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:33:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 22:36:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_manager(const char *error_msg)
{
	write(STDERR_FILENO, RED, ft_strlen(RED));
	write(STDERR_FILENO, "Error.\n", 8);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, RESET, ft_strlen(RESET));
	// table_holder(NULL, true);
	exit(EXIT_FAILURE);
}
