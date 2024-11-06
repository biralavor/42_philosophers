/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:32:22 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 19:37:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief This function calculates the length of a string.
 * It iterates through the string, and increments a counter until the end
 * of the string.
 * @param str The string to calculate the length
 * @return int The length of the string
 */
int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
