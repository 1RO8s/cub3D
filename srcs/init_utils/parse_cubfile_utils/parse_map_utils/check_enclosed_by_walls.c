/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enclosed_by_walls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:19:11 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	put_error_msg_is_not_map_enclosed(void)
{
	printf("%s%s\n", ERR_PROMPT, EMSG_MAP_NOT_ENCLOSED);
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
				if (flood_fill(map, x, y, (bool **)visited) != true)
					return (false);
			x++;
		}
		y++;
	}
	return (ENUM_TRUE);
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
	return ((bool **)visited);
}

static t_bool	process_false_or_error(t_bool is_surrounded)
{
	if (is_surrounded == ENUM_FALSE)
		put_error_msg_is_not_map_enclosed();
	return (is_surrounded);
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
	t_bool	is_surrounded;

	visited = init_visited(&parse->game->map);
	if (visited == NULL)
		return (EXIT_FAILURE);
	start_x = parse->player_grid.x;
	start_y = parse->player_grid.y;
	map = &parse->game->map;
	is_surrounded = ENUM_TRUE;
	is_surrounded = flood_fill(map, start_x, start_y, visited);
	if (process_false_or_error(is_surrounded) != ENUM_TRUE)
		return (EXIT_FAILURE);
	is_surrounded = is_enclosed_on_remaining_area(map, visited);
	if (process_false_or_error(is_surrounded) != ENUM_TRUE)
		return (EXIT_FAILURE);
	(void)line;
	return (EXIT_SUCCESS);
}
// debug code
//printf("-- End flood_fill()\n");//debug
//put_visited(parse->game->debug.fd, visited, map);
