/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enclosed_by_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/03 23:36:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to perform flood-fill from a given position
bool flood_fill(char **map, int rows, int cols, int x, int y, bool visited[MAX_ROWS][MAX_COLS])
{
	// Base cases
	if (x < 0 || x >= cols || y < 0 || y >= rows)
	{
		return false;  // Reached the map boundary, not enclosed
	}
	if (map[y][x] == '1' || visited[y][x])
	{
		return (true);  // Reached a wall or already visited
	}
	// Mark the current position as visited
	visited[y][x] = true;
	// Recursively flood-fill in all four directions
	bool	up = flood_fill(map, rows, cols, x, y - 1, visited);
	bool	down = flood_fill(map, rows, cols, x, y + 1, visited);
	bool	left = flood_fill(map, rows, cols, x - 1, y, visited);
	bool	right = flood_fill(map, rows, cols, x + 1, y, visited);
	return (up && down && left && right);  // All directions must be enclosed
}

// Improved function to check if the map is enclosed by walls
bool is_enclosed_by_walls(const char *line, t_parse *parse)
{
	bool	visited[MAX_ROWS][MAX_COLS] = {false};
	int start_x = -1, start_y = -1;
	int	x;
	int	y;
	int	rows;
	int	cols;
	
	x = parse->player_grid.x;
	y = parse->player_grid.y;
	rows = parse->map->width;
	cols = parse->map->height;
	// Find the first open space ('0') to start the flood-fill
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
			{
				start_x = x;
				start_y = y;
				break;
			}
		}
		if (start_x != -1) break;
	}
	// If no starting point found, return false (invalid map)
	if (start_x == -1 || start_y == -1)
	{
		printf("No starting position found on the map.\n");
		return false;
	}
	// Perform flood-fill starting from the initial position
	if (!flood_fill(map, rows, cols, start_x, start_y, visited))
	{
		printf("Map is not enclosed by walls.\n");
		return false;
	}
	
	return true;  // The map is properly enclosed
}
