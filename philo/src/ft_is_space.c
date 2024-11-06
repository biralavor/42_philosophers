/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:26:42 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 19:36:22 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function checks if a character is a space.
 * It returns true if the character is a space, and false otherwise.
 * @param c The character to check
 * @return true If the character is a space
 */
bool	ft_is_space(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}
