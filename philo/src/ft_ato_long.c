/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:57:56 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 19:35:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief This function converts a string to an integer.
 * It skips whitespaces, and then checks if the number is negative.
 * It then converts the string to an integer, and returns it.
 * @param string The string to convert
 * @return long The integer converted from the string
 */
long	ft_ato_long(const char *string)
{
	long	nbr;
	int		sign;
	char	*str;

	sign = 1;
	str = (char *)string;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
