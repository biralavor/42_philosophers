/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/24 21:52:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_table	t_table;

typedef struct s_set
{
	long	total_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	total_meals;
}			t_set;

typedef struct s_chopstick
{
	int				chops_id;
	pthread_mutex_t	*chops_mtx;
}					t_chops;

typedef struct s_philo
{
	int			id;
	long		got_meals;
	long		time_of_last_meal;
	bool		full;
	pthread_t	*th_id;
	t_chops		*l_chops;
	t_chops		*r_chops;
	t_table		*table;
}				t_philo;

struct s_table
{
	long			start_time;
	bool			this_is_the_end;
	t_set			*set;
	t_philo			*philo;
	pthread_mutex_t	*ph_mtx;
	t_chops			*chopstick;
};

bool	arguments_validation(int ac, char **av);
t_table	*table_alloc(t_table *table, char **av);
void	table_parsing(t_table *table, char **av);
long	ft_atoi_long_int(const char *string);
t_table	*table_holder(t_table *table, bool destroy);
void	table_mutex_init(t_table *table);

#endif