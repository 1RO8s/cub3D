/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enclosed_by_walls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/30 19:40:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool flood_fill_iterative(t_map *map, int start_x, int start_y, bool **visited) {
    // Ensure the start position is within bounds
    if (start_x < 0 || start_x >= map->width || start_y < 0 || start_y >= map->height) {
        return false;
    }

    // Allocate a stack for flood-fill
	int	size = map->width * map->height;
    t_point *stack = (t_point *)malloc(map->width * map->height * sizeof(t_point));
    if (!stack) {
        perror("Failed to allocate memory for flood-fill stack");
        return false;
    }

    int stack_size = 0; // Stack pointer

    // Push the starting point onto the stack
    stack[stack_size] = (t_point){start_x, start_y};

    bool is_surrounded = true;

    // Direction vectors for moving in 4 directions
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

	stack_size = 1;
    while (stack_size > 0) {
        // Pop a point from the stack
        t_point current = stack[--stack_size];

        int x = current.x;
        int y = current.y;

        // Check boundaries
        if (x < 0 || x >= map->width || y < 0 || y >= map->height) {
            is_surrounded = false;
            continue;
        }

        // Skip already visited cells or walls
        if (map->data[y][x] == '1' || visited[y][x]) {
            continue;
        }

        // Check for invalid map cells
        if (map->data[y][x] != '0') {
            is_surrounded = false;
            continue;
        }

        // Mark the cell as visited
        visited[y][x] = true;

        // Push all valid neighbors onto the stack
		int	i;
		i = 0;
		while (i < 4)
		{
        //for (int i = 0; i < 4; i++) {
            stack[stack_size] = (t_point){x + dx[i], y + dy[i]};
			stack_size++;
			i++;
        }
    }

    free(stack);
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

	visited = (bool **)malloc(sizeof(bool *) * (size_t)map->height);
	i = 0;
	while (i < (size_t)map->height)
	{
		visited[i] = (bool *)malloc(sizeof(bool) * (size_t)map->width);
		ft_memset(visited[i], (int)false, (size_t)map->width);
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
