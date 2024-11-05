/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:57:56 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/04 18:17:33 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi_long_int(const char *string)
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
