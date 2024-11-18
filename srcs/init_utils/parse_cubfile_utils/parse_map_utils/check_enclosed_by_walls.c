/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enclosed_by_walls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/19 04:13:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief flood-fill from a given position
 *
 * @return true(enclosed map) false(not enclosed map)
 */
bool	flood_fill(
		t_map *map, int x, int y, bool visited[MAX_ROWS][MAX_COLS])
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (false);
	if (map->data[y][x] == '1' || visited[y][x])
		return (true);
	if (map->data[y][x] != '0' || visited[y][x])
		return (false);
	visited[y][x] = true;
	up = flood_fill(map, x, y - 1, visited);
	down = flood_fill(map, x, y + 1, visited);
	left = flood_fill(map, x - 1, y, visited);
	right = flood_fill(map, x + 1, y, visited);
	return (up && down && left && right);
}

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
		t_map *map, bool visited[MAX_ROWS][MAX_COLS])
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
				if (flood_fill(map, x, y, visited) != true)
					return (false);
			x++;
		}
		y++;
	}
	return (true);
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
	bool	visited[MAX_ROWS][MAX_COLS];
	int		start_x;
	int		start_y;
	t_map	*map;

	ft_memset(visited, (int)false, sizeof(visited));
	start_x = parse->player_grid.x;
	start_y = parse->player_grid.y;
	map = &parse->game->map;
	if (flood_fill(map, start_x, start_y, visited) != true)
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
