/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.arg_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:24:28 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/06 16:50:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Check if the amount of arguments is correct
 * @param ac Number of arguments
 * @return true if the amount is between 5 or 6 arguments.
 */
bool	arguments_amount(int ac)
{
	if (ac == 5 || ac == 6)
		return (true);
	printf(RED"Error.\n");
	printf(RED"Wrong arguments amount.\n");
	printf(YELLOW"Please, read the instructions.\n"RESET);
	return (false);
}

/**
 * @brief Check if the arguments are positive numbers
 * @param av Arguments
 * @return true if all arguments are numbers and positive numbers,
 * otherwise false.
 */
bool	av_is_a_positive_number(char **av)
{
	int	idx;
	int	c;

	idx = 0;
	while (av[++idx])
	{
		c = -1;
		while (av[idx][++c])
		{
			while (ft_is_space(av[idx][c]))
				c++;
			if (av[idx][c] == '+')
				c++;
			else if (av[idx][c] == '-')
				return (false);
			if (av[idx][c] >= '0' || av[idx][c] <= '9')
			{
				if (av[idx][c] == '\0' && av[idx + 1] == NULL)
					return (true);
			}
		}
	}
	return (false);
}

/**
 * @brief Check if the length of the number is valid based on INT MAX length
 * @param av Arguments
 * @return true if the length of the number is less than 11 characters.
 */
bool	is_valid_length_number(char **av)
{
	int	len;
	int	idx;
	int	c;

	len = 0;
	idx = 1;
	while (av)
	{
		c = -1;
		while (av[idx][++c])
			len++;
		if (len < 11)
			return (true);
		idx++;
	}
	return (false);
}

/**
 * @brief Check if the number is under or equal INT MAX
 * @param ac Number of arguments
 * @param av Arguments
 * @return true if the number is under or equal INT MAX, otherwise false.
 */
bool	is_number_under_intmax(int ac, char **av)
{
	int		idx;
	long	nbr;

	idx = 0;
	nbr = 0;
	ac -= 1;
	while (av[++idx])
	{
		nbr = ft_atoi_long_int(av[idx]);
		if (nbr <= INT_MAX)
		{
			if (idx == ac)
				return (true);
		}
		else
			break ;
	}
	return (false);
}

/**
 * @brief Check if the arguments are valid
 */
bool	arguments_validation_manager(int ac, char **av)
{
	if (arguments_amount(ac)
		&& av_is_a_positive_number(av)
		&& is_valid_length_number(av)
		&& is_number_under_intmax(ac, av))
		return (true);
	return (false);
}
