/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 16:26:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (set_direction(direction, player));
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
