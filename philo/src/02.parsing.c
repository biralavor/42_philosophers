/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/25 19:30:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table_alloc(t_table *table, char **av)
{
	table = malloc(sizeof(t_table));
	table->set = malloc(sizeof(t_set));
	table->philo = malloc(sizeof(t_philo) * ft_atoi_long_int(av[1]));
	table->philo->th_id = malloc(sizeof(pthread_t)  * ft_atoi_long_int(av[1]));
	table->ph_mtx = malloc(sizeof(pthread_mutex_t));
	return (table);
}

void	table_parsing(t_table *table, char **av)
{
	table = table_alloc(table, av);
	table->set->total_philos = ft_atoi_long_int(av[1]);
	table = table_holder(table, false);
}

bool	arguments_amount(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf(RED"Error.\n");
		printf(RED"Wrong arguments amount.\n");
		printf(YELLOW"Please, read the instructions.\n"RESET);
		return (false);
	}
	return (true);
}

bool	is_space(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

bool	av_is_a_number(char **av)
{
	int	idx;
	int	c;

	idx = 1;
	while (av[idx])
	{
		c = 0;
		while(av[idx][c])
		{
			while (is_space(av[idx][c]))
				c++;
			if (av[idx][c] == '+' || av[idx][c] == '-')
				c++;
			if (av[idx][c] >= '0' || av[idx][c] <= '9')
				return (true);
			else
				break ;
		}
		idx++;
	}
	return (false);
}

bool	is_valid_length_number(char **av)
{
	int	len;
	int	idx;
	int	c;

	len = 0;
	idx = 1;
	while(av)
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
			if(idx == ac)
				return (true);
		}
		else
			break ;
	}
	return (false);
}

bool	arguments_validation_manager(int ac, char **av)
{
	if (arguments_amount(ac)
		&& av_is_a_number(av)
		&& is_valid_length_number(av)
		&& is_number_under_intmax(ac, av))
		return (true);
	return (true);
}
