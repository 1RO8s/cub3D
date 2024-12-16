/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:42:15 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/16 16:07:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_stack(t_stack *stack, int initial_capacity)
{
	stack->data = (t_point *)malloc(initial_capacity * sizeof(t_point));
	if (stack->data == NULL)
	{
		perror("Failed to allocate stack\n");
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
 * @brief Check if the current grid is checked or within boundaries
 *
 * @param current
 * @param map
 * @param is_surrounded
 *
 * @return CONTINUE(2) or EXIT_SUCCESS(0)
 */
int	check_grid_is_not_visited(t_point current, t_map *map,
		t_bool *is_surrounded, bool **visited)
{
	if (current.x < 0 || current.x >= map->width
		|| current.y < 0 || current.y >= map->height)
	{
		*is_surrounded = ENUM_FALSE;
		return (CONTINUE);
	}
	if (visited[current.y][current.x] == true
		|| map->data[current.y][current.x] == '1')
	{
		if (map->data[current.y][current.x] != '0'
			&& map->data[current.y][current.x] != '1')
			*is_surrounded = ENUM_FALSE;
		return (CONTINUE);
	}
	return (EXIT_SUCCESS);
}

int	initialize_for_flood_fill(t_stack *stack, int start_x, int start_y)
{
	if (init_stack(stack, DFLT_STACK_SIZE) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (push(stack, (t_point){start_x, start_y}) != EXIT_SUCCESS)
	{
		free(stack->data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief flood_fill algorythm ( stack-based iteration )
 *
 * @return true(1) or false(0) or error(-1)
 */
t_bool	flood_fill(t_map *map, int start_x, int start_y, bool **visited)
{
	t_stack		stack;
	t_bool		is_surrounded;
	t_point		current;

	ft_printf(">> flood_fill <<\n");
	if (initialize_for_flood_fill(&stack, start_x, start_y) != EXIT_SUCCESS)
		return (ENUM_ERROR);
	is_surrounded = ENUM_TRUE;
	while (is_empty(&stack) == false)
	{
		current = pop(&stack);
		if (check_grid_is_not_visited(current, map, &is_surrounded, visited)
			== CONTINUE)
			continue ;
		visited[current.y][current.x] = true;
		if (push_neighbors_onto_stack(current.x, current.y, &stack)
			!= EXIT_SUCCESS)
		{
			is_surrounded = ENUM_ERROR;
			break ;
		}
	}
	free(stack.data);
	return (is_surrounded);
}
