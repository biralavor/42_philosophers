/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:11 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/29 15:32:50 by umeneses         ###   ########.fr       */
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
# include <errno.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define ORANGE "\033[0;91m"
# define MAGENT "\033[0;95m"
# define RESET "\033[0m"

typedef enum	e_mtx_opcode
{
	INIT,
	CREATE,
	JOIN,
	LOCK,
	UNLOCK,
	DETACH,
	DESTROY,
}	t_mtx_opcode;

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
	pthread_mutex_t	chops_mtx;
}					t_chops;

typedef struct s_philo
{
	int			id;
	long		got_meals;
	long		time_of_last_meal;
	bool		full;
	pthread_t	*th_id;
	t_chops		*first_chops;
	t_chops		*second_chops;
	t_table		*table;
}				t_philo;

struct s_table
{
	long			start_time;
	bool			this_is_the_end;
	bool			all_threads_ready_togo;
	t_set			*set;
	t_philo			*philo;
	pthread_mutex_t	*ph_mtx;
	pthread_mutex_t	*table_mtx;
	t_chops			*chopstick;
};

/* validation functions */
bool	arguments_validation_manager(int ac, char **av);
bool	arguments_amount(int ac);
bool	av_is_a_positive_number(char **av);
bool	ft_is_space(const char c);
bool	is_valid_length_number(char **av);
bool	is_number_under_intmax(int ac, char **av);

/* memory allocation functions */
t_table	*table_alloc(t_table *table, char **av);
void	*ft_safe_malloc(size_t size);
void	error_manager(const char *error_msg);
t_table	*table_holder(t_table *table, bool destroy);

/* mutex handler functions */
void	safe_mutex_handler(pthread_mutex_t *mutex, t_mtx_opcode opcode);
void	error_mutex_handler(int status, int opcode);

/* thread handler functions*/
void	safe_thread_handler(pthread_t *th_id, void *(*func_ptr)(void *), \
			void *data, t_mtx_opcode opcode);

/* table initialization */
void	table_parsing(t_table *table, char **av);
void	table_init(t_table *table);
void	philo_init_runner(t_table *table);
void	get_chopsticks(t_philo *philo, t_chops *chopstick, int philo_pos);

/* getters and setters functions */
void	set_bool(pthread_mutex_t *mutex, bool *destination, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_long(pthread_mutex_t *mutex, long *destination, long value);
long	get_long(pthread_mutex_t *mutex, long *value);
bool	this_is_the_end_of_dinner(t_table *table);

/* LIBFT utility functions */
int		ft_strlen(const char *str);
long	ft_atoi_long_int(const char *string);

void	*routine(void *arg);

#endif