/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:42:15 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/01 03:41:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_stack(t_stack *stack, int initial_capacity)
{
	stack->data = (t_point *)malloc(initial_capacity * sizeof(t_point));
	if (stack->data == NULL)
	{
		perror("Failed to allocate stack");
		return (EXIT_FAILURE);
	}
	stack->top = 0;
	stack->capacity = initial_capacity;
	return (EXIT_SUCCESS);
}

/**
 * @brief Push all neighbors onto stack
 *
 * @param EXIT_SUCCESS or EXIT_FAILURE
 */
static int	push_neighbors_onto_stack(int x, int y, t_stack *stack)
{
	static int	dx[4] = {0, 0, -1, 1};
	static int	dy[4] = {-1, 1, 0, 0};
	int			new_x;
	int			new_y;
	int			i;

	i = 0;
	while (i < 4)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (push(stack, (t_point){new_x, new_y}) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief flood_fill algorythm ( stack-based iteration )
 *
 * @return true or false
 */
bool	flood_fill_iterative(
			t_map *map, int start_x, int start_y, bool **visited)
{
    t_stack stack;
    bool	is_surrounded;
	int 	x;
	int 	y;

    init_stack(&stack, 100);
    if (push(&stack, (t_point){start_x, start_y}) != EXIT_SUCCESS)
	{
		free(stack.data);
		return (false);
	}
	is_surrounded = true;
	while (is_empty(&stack) == false)
	{
		t_point current = pop(&stack);
		x = current.x;
		y = current.y;
		// Boundary check
		if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		{
			is_surrounded = false;
			continue;
		}
		// Skip already visited or wall cells
		if (visited[y][x] || map->data[y][x] == '1')
			continue;
		visited[y][x] = true;
		// Push neighbors onto the stack
		if (push_neighbors_onto_stack(x, y, &stack) != EXIT_SUCCESS)
		{
			is_surrounded = false;
			break ;
		}
	}
	free(stack.data);
	return is_surrounded;
}
