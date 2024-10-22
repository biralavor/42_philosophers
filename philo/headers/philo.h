/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/22 17:46:12 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_setup
{
	long int	total_philos;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	total_meals;
}				t_setup;


typedef struct s_table
{
	pthread_mutex_t	*mtx_philo;
	t_setup			*setup;
}					t_table;

bool	arguments_validation(int ac, char **av);
t_table	*table_alloc(t_table *table);
void	table_parsing(t_table *table, char **av);
long int		ft_atoi_long_int(const char *string);
t_table	*table_holder(t_table *table, bool destroy);
void	table_mutex_init(t_table *table);

#endif