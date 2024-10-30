/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:03:55 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/30 16:09:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner_routine(void *arg)
{
	int	mails = 0;
	int *result = malloc(sizeof(int)); // it will be freed after pthread_join()
	int idx = 0;
	printf("Thread %d is running\n", *(int *)arg);
	while (idx < 2)
	{
		mails++;
		mails = mails * (*(int *)arg);
		idx++;
	}
	*result = mails;
	free(arg);
	return ((void *) result);
}

int main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (!arguments_validation_manager(ac, av))
		exit(EXIT_FAILURE);
	table_parsing(table, av);
	table = table_holder(NULL, false);
	table_init(table);
	// dinner_manager(table);
	table_holder(NULL, true);
	exit(EXIT_SUCCESS);
}
