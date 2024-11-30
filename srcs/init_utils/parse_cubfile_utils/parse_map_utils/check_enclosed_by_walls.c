/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enclosed_by_walls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/01 01:04:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Point structure for stack elements
typedef struct {
    int x;
    int y;
} Point;

// Define a Dynamic Stack
typedef struct {
    Point *data;
    int top;
    int capacity;
} Stack;

// Initialize the stack
void init_stack(Stack *stack, int initial_capacity) {
    stack->data = malloc(initial_capacity * sizeof(Point));
    if (!stack->data) {
        perror("Failed to allocate stack");
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
    stack->capacity = initial_capacity;
}

// Push an element onto the stack
void push(Stack *stack, Point value) {
	int	old_size;

    if (stack->top >= stack->capacity) {
		old_size = stack->capacity * sizeof(Point);
        stack->capacity *= 2; // Double the capacity
        stack->data = (Point *)ft_realloc_tentative(stack->data, stack->capacity * sizeof(Point), old_size);
		ft_printf("realloc\n");
        if (!stack->data) {
            perror("Failed to reallocate stack");
            exit(EXIT_FAILURE);
        }
    }
    stack->data[stack->top++] = value;
}

// Pop an element from the stack
Point pop(Stack *stack) {
    return stack->data[--stack->top];
}

// Check if the stack is empty
bool is_empty(Stack *stack) {
    return stack->top == 0;
}

// Free the stack memory
void free_stack(Stack *stack) {
    free(stack->data);
}

/**
 * @brief flood_fill algorythm ( stack-based iteration )
 *
 * @param map
 * @param start_x
 * @param start_y
 * @param visited
 *
 * @return 
 */
bool flood_fill_iterative(t_map *map, int start_x, int start_y, bool **visited)
{
    Stack stack;
    init_stack(&stack, 100); // Start with an initial capacity of 100

    push(&stack, (Point){start_x, start_y});
    bool is_surrounded = true;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (!is_empty(&stack)) {
        Point current = pop(&stack);
        int x = current.x;
        int y = current.y;

        // Boundary check
        if (x < 0 || x >= map->width || y < 0 || y >= map->height) {
            is_surrounded = false;
            continue;
        }

        // Skip already visited or wall cells
        if (visited[y][x] || map->data[y][x] == '1') {
            continue;
        }

        visited[y][x] = true;

        // Push neighbors onto the stack
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            push(&stack, (Point){new_x, new_y});
        }
    }

    free_stack(&stack); // Free stack memory
    return is_surrounded;
}

/**
 * @brief flood-fill from a given position
 *
 * @return true(enclosed map) false(not enclosed map)
 */
//bool	flood_fill(
//		t_map *map, int x, int y, bool **visited)
//{
//	bool	up;
//	bool	down;
//	bool	left;
//	bool	right;
//
//	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
//		return (false);
//	if (map->data[y][x] == '1' || visited[y][x])
//		return (true);
//	if (map->data[y][x] != '0' || visited[y][x])
//		return (false);
//	visited[y][x] = true;
//	up = flood_fill(map, x, y - 1, visited);
//	down = flood_fill(map, x, y + 1, visited);
//	left = flood_fill(map, x - 1, y, visited);
//	right = flood_fill(map, x + 1, y, visited);
//	return (up && down && left && right);
//}

// debug
//void	put_visited(int fd, bool visited[MAX_ROWS][MAX_COLS], t_map *map)
//{
//	for (int r = 0; r < map->height; r++)
//	{
//		for (int c = 0; c < map->width; c++)
//		{
//			ft_dprintf(fd, "%d", visited[r][c]);
//		}
//		ft_dprintf(fd, "\n");
//	}
//}

// check small map size
//#define CHECK_ROWS 150
//#define CHECK_COLS 100
//	bool	visited[CHECK_ROWS][CHECK_COLS];
//	for (int i = 0; i < CHECK_ROWS; i++) {
//    	for (int j = 0; j < CHECK_COLS; j++) {
//    	    printf("%d", visited[i][j]);
//    	}
//		printf("\n");
//	}

static void	put_error_msg_is_not_map_enclosed(void)
{
	ft_dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_MAP_NOT_ENCLOSED);
}

static bool	is_enclosed_on_remaining_area(
		t_map *map, bool **visited)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == '0' && visited[y][x] == false)
				if (flood_fill_iterative(map, x, y, (bool **)visited) != true)
					return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static bool	**init_visited(t_map *map)
{
	bool	**visited;
	size_t	i;

	visited = (bool **)malloc((size_t)map->height * sizeof(bool *));
	i = 0;
	while (i < (size_t)map->height)
	{
		visited[i] = (bool *)ft_calloc((size_t)map->width, sizeof(bool));
		i++;
	}
	printf("map size : rows[%d] cols[%d]\n", map->height, map->width);
	//exit(0);
	return ((bool **)visited);
}

/**
 * @brief check if the map is enclosed by walls
 *
 * @param line is Not required (just to call the function pointer)
 * @param parse
 *
 * @return EXIT_SUCCESS(0) or EXIT_FAILURE(1)
 */
int	check_enclosed_by_walls(const char *line, t_parse *parse)
{
	bool	**visited;
	int		start_x;
	int		start_y;
	t_map	*map;

	visited = init_visited(&parse->game->map);
	if (visited == NULL)
		return (EXIT_FAILURE);
	start_x = parse->player_grid.x;
	start_y = parse->player_grid.y;
	map = &parse->game->map;
	if (flood_fill_iterative(map, start_x, start_y, (bool **)visited) != true)
	{
		put_error_msg_is_not_map_enclosed();
		return (EXIT_FAILURE);
	}
	if (is_enclosed_on_remaining_area(map, visited) != true)
	{
		put_error_msg_is_not_map_enclosed();
		return (EXIT_FAILURE);
	}
	(void)line;
	return (EXIT_SUCCESS);
}
// debug code
//printf("-- End flood_fill()\n");//debug
//put_visited(parse->game->debug.fd, visited, map);
