/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:42:15 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/12 01:40:51 by kamitsui         ###   ########.fr       */
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
 * @brief 
 *
 * @param current
 * @param map
 * @param is_surrounded
 *
 * @return CONTINUE(2) or EXIT_SUCCESS(0)
 */
int	check_boundary_or_visited(t_point current, t_map *map,
		bool *is_surrounded, bool **visited)
{
	if (is_surrounded == NULL)
		return (EXIT_FAILURE);
	if (current.x < 0 || current.x >= map->width
		|| current.y < 0 || current.y >= map->height)
	{
		*is_surrounded = false;
		return (CONTINUE);
	}
	if (visited[current.y][current.x] == true
		|| map->data[current.y][current.x] == '1')
		return (CONTINUE);
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
	t_stack	stack;
	bool	is_surrounded;
	t_point	current;

	init_stack(&stack, 100);
	if (push(&stack, (t_point){start_x, start_y}) != EXIT_SUCCESS)
	{
		free(stack.data);
		return (false);
	}
	is_surrounded = true;
	while (is_empty(&stack) == false)
	{
		current = pop(&stack);
		if (check_boundary_or_visited(current, map, &is_surrounded, visited) == CONTINUE)
			continue ;
		visited[current.y][current.x] = true;
		if (push_neighbors_onto_stack(current.x, current.y, &stack) != EXIT_SUCCESS)
		{
			is_surrounded = false;
			break ;
		}
	}
	free(stack.data);
	return (is_surrounded);
}
