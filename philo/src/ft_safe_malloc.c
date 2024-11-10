/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:55:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/11/10 13:11:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief This function allocates memory safely.
 * It uses the malloc function to allocate memory, and if the pointer is NULL,
 * it calls the error manager.
 * @param size The size of the memory to allocate
 * @return void* The pointer to the allocated memory
 */
void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (NULL == ptr)
		error_manager("Malloc failed.\n");
	return (ptr);
}
