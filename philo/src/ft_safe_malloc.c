/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:55:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/27 21:56:12 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (NULL == ptr)
		error_manager("Error.\nMalloc failed.\n");
	return (ptr);
}
