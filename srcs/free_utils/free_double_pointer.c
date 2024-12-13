/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:29:02 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 20:00:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Free the memory and set the pointer to NULL.
 * @param[in] ptr The pointer to be freed.
 * @return NULL always.
 */
void	*ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	return (NULL);
}

void	free_double_pointer(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		array[i] = ft_free(array[i]);
		i++;
	}
	ft_free(array);
}

void	free_double_pointer_n(char **array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		array[i] = ft_free(array[i]);
		i++;
	}
	array = ft_free(array);
}
