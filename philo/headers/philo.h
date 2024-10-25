/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/25 20:37:36 by umeneses         ###   ########.fr       */
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
# include <limits.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define ORANGE "\033[0;91m"
# define MAGENT "\033[0;95m"
# define RESET "\033[0m"

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


/* validation functions */

bool	arguments_validation_manager(int ac, char **av);
bool	arguments_amount(int ac);
bool	av_is_a_number(char **av);
bool	ft_is_space(const char c);
bool	is_valid_length_number(char **av);
bool	is_number_under_intmax(int ac, char **av);


void	error_manager(const char *error_msg);
int		ft_strlen(const char *str);
t_table	*table_alloc(t_table *table, char **av);
void	table_parsing(t_table *table, char **av);
long	ft_atoi_long_int(const char *string);
t_table	*table_holder(t_table *table, bool destroy);
void	table_mutex_init(t_table *table);

void	*routine(void *arg);

#endif