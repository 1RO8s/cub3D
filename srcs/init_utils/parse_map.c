/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 12:02:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_direction(
	double ray_x, double ray_y, double plane_x, double plane_y)
{
	player->ray_dir.x = ray_x;
	player->ray_dir.y = ray_y;
	player->camera_forcal_plane.x = 0.66;
	player->camera_forcal_plane.y = 0;
}

/**
 * @brief initialize the player
 *
 * @note
 *  player view point , ray direction, camera forcal plane direction
 */
static void	initialize_player(t_player *player, int x, int y, char direction)
{
	player->view_point.x = x + 0.5;
	player->view_point.y = y + 0.5;
	if (direction == 'N')
	{
		player->ray_dir.x = 0;
		player->ray_dir.y = -1;
		player->camera_forcal_plane.x = 0.66;
		player->camera_forcal_plane.y = 0;
	}
	else if (direction == 'S')
	{
		player->ray_dir.x = 0;
		player->ray_dir.y = 1;
		player->camera_forcal_plane.x = -0.66;
		player->camera_forcal_plane.y = 0;
	}
	else if (direction == 'W')
	{
		player->ray_dir.x = -1;
		player->ray_dir.y = 0;
		player->camera_forcal_plane.x = 0;
		player->camera_forcal_plane.y = -0.66;
	}
	else if (direction == 'E')
	{
		player->ray_dir.x = 1;
		player->ray_dir.y = 0;
		player->camera_forcal_plane.x = 0;
		player->camera_forcal_plane.y = 0.66;
	}
}

/**
 * @brief check the player position
 */
static bool	is_player_position(char map_point)
{
	return (map_point == 'N' || map_point == 'S'
		|| map_point == 'W' || map_point == 'E');
}

/**
 * @brief Parse the map and find the player's position
 */
void	parse_map(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player_position(map->data[y][x]) == true)
			{
				initialize_player(player, x, y, map->data[y][x]);
				map->data[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	debug_map_data(*map);
	exit(0);
}
