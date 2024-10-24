/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:57:56 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/22 17:00:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoi_long_int(const char *string)
{
	long int	nbr;
	int			sign;
	char		*str;

	sign = 1;
	str = (char *)string;
	while((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while(*str == '-' || *str == '+')
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
