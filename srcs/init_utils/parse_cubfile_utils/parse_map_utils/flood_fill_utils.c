/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:20:47 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/01 03:30:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Push an element onto the stack
 */
int	push(t_stack *stack, t_point value)
{
	int	old_size;

	if (stack->top >= stack->capacity)
	{
		old_size = stack->capacity * sizeof(t_point);
		stack->capacity *= 2;
		stack->data = (t_point *)ft_realloc_tentative(
				stack->data, stack->capacity * sizeof(t_point), old_size);
		if (stack->data == NULL)
		{
			perror("Failed to reallocate stack");
			return (EXIT_FAILURE);
		}
	}
	stack->data[stack->top++] = value;
	return (EXIT_SUCCESS);
}

/**
 * @brief Pop an element from the stack
 *
 * @return (t_point){(int)x, (int)y}
 */
t_point	pop(t_stack *stack)
{
	return (stack->data[--stack->top]);
}

/**
 * @brief Check if the stack is empty
 *
 * @return false or true
 */
bool	is_empty(t_stack *stack)
{
	return (stack->top == 0);
}
