/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enclosed_by_walls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/11 04:21:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to perform flood-fill from a given position
bool flood_fill(t_map *map, int x, int y, bool visited[MAX_ROWS][MAX_COLS])
{
	// Base cases
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
	{
		return false;  // Reached the map boundary, not enclosed
	}
	if (map->data[y][x] == '1' || visited[y][x])
	{
		return (true);  // Reached a wall or already visited
	}
	if (map->data[y][x] != '0' || visited[y][x])
		return (false);
	// Mark the current position as visited
	visited[y][x] = true;
	// Recursively flood-fill in all four directions
	bool	up = flood_fill(map, x, y - 1, visited);
	bool	down = flood_fill(map, x, y + 1, visited);
	bool	left = flood_fill(map, x - 1, y, visited);
	bool	right = flood_fill(map, x + 1, y, visited);
	return (up && down && left && right);  // All directions must be enclosed
}

void	put_visited(bool visited[MAX_ROWS][MAX_COLS], t_map *map)
{
	for (int r = 0; r < map->height; r++)
	{
		for (int c = 0; c < map->width; c++)
		{
			printf("%d", visited[r][c]);
		}
		printf("\n");
	}
}

// Improved function to check if the map is enclosed by walls
int check_enclosed_by_walls(const char *line, t_parse *parse)
{
	bool	visited[MAX_ROWS][MAX_COLS] = {false};
	int start_x = -1, start_y = -1;
	t_map	*map;
	
	start_x = parse->player_grid.x;
	start_y = parse->player_grid.y;
	map = &parse->game->map;
	// Perform flood-fill starting from the initial position
	if (flood_fill(map, start_x, start_y, visited) != true)
	{
		dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_MAP_NOT_ENCLOSED);
		return (EXIT_FAILURE);
	}
	(void)line;
	return (EXIT_SUCCESS);
}
// debug code
//printf("-- End flood_fill()\n");//debug
//put_visited(visited, map);
