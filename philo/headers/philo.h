/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:11 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/29 15:49:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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
# define BWHITE "\033[1;37m"
# define RESET "\033[0m"

# define DEBUG_MODE 0
# define PHILOS_LIMIT 200
# define CACHE_LINE_SIZE 64

typedef enum e_mtx_opcode
{
	INIT,
	CREATE,
	JOIN,
	LOCK,
	UNLOCK,
	DETACH,
	DESTROY,
}	t_mtx_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_code;

typedef enum e_philo_status
{
	GOT_1ST_CHOPSTICK,
	GOT_2ND_CHOPSTICK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
}	t_philo_status;

typedef struct s_chopstick
{
	int				chops_id;
	pthread_mutex_t	chops_mtx;
}					t_chops;

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	long			got_meals;
	long			timeof_lastmeal;
	bool			full;
	pthread_mutex_t	philo_mtx;
	pthread_t		th_id;
	t_chops			*first_chops;
	t_chops			*second_chops;
	t_table			*table;
	char			padding[CACHE_LINE_SIZE];
}					t_philo;

struct s_table
{
	long			start_time;
	long			running_threads_idx;
	bool			this_is_the_end;
	bool			all_threads_up;
	long			total_philos;
	long			timeto_die;
	long			timeto_eat;
	long			timeto_sleep;
	long			total_meals;
	t_philo			*philos;
	t_chops			*chopsticks;
	pthread_mutex_t	table_mtx;
	pthread_mutex_t	printer_mtx;
	pthread_t		monitor_thread;
};

/* LIBFT utility functions */
int		ft_strlen(const char *str);
long	ft_atoi_long(const char *string);
long	ft_gettime(t_time_code timecode);
void	precise_usleep(long microsec, t_table *table);

/* validation functions */
bool	arguments_validation_manager(int ac, char **av);
bool	arguments_amount(int ac);
bool	argument_number_validation(char **av);
bool	av_is_a_positive_number(char **av, int idx);
bool	ft_is_digit(char c);
bool	ft_is_space(const char c);
bool	is_valid_length_number(char **av);
bool	is_number_under_intmax(int ac, char **av);

/* memory allocation functions */
t_table	*table_alloc(t_table *table);
void	*ft_safe_malloc(size_t size);

/* mutex handler functions */
void	safe_mutex_handler(pthread_mutex_t *mutex, t_mtx_opcode opcode);
void	mutex_error_handler(int status, int opcode);

/* thread handler functions*/
void	safe_thread_handler(pthread_t *th_id, void *(*func_ptr)(void *), \
			void *data, t_mtx_opcode opcode);
void	pthread_error_handler(int status, int opcode);

/* table initialization */
void	table_parsing(t_table *table, char **av);
void	table_init(t_table *table);
void	philo_init_runner(t_table *table, int idx);
void	set_chopsticks(t_philo *philo, t_chops *chopstick, int philo_pos);

/* getters and setters functions */
void	set_bool(pthread_mutex_t *mutex, bool *destination, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_long(pthread_mutex_t *mutex, long *destination, long value);
long	get_long(pthread_mutex_t *mutex, long *value);
bool	is_this_the_end(t_table *table);

/* dinner manager functions */
void	holdon_until_all_threads(t_table *table);
bool	all_threads_are_running(pthread_mutex_t *mutex, long *threads,
			long total_philos);
void	increase_long(pthread_mutex_t *mutex, long *value);
void	dinner_manager(t_table *table);
void	*dinner_runner(void *data);
void	*monitor_runner(void *data);

/* printer functions */
void	printer_manager(t_philo_status status,
			t_philo *philo, int debug);
void	printer_with_mutex_classic(t_philo_status status,
			t_philo *philo, long elapsed);
void	printer_with_mutex_chopsticks(t_philo_status status,
			t_philo *philo, long elapsed);
void	printer_with_mutex_debug(t_philo_status status,
			t_philo *philo, long elapsed);
void	unsync_this_philo(t_philo *philo);

/* dinner routines functions */
void	let_philo_eat_routine(t_philo *philo);
void	let_philo_think_routine(t_philo *philo, bool before_spinlock);
void	let_philo_sleep_routine(t_philo *philo);
bool	is_philo_dead_manager(t_philo *philo);
void	*lonely_philo_routine(void *data);

/* clear and error manager functions */
void	error_manager(const char *error_msg);
void	free_table(t_table *table);

#endif