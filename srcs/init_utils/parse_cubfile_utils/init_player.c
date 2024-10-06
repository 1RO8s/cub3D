/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 01:17:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief initialize the player
 *
 * @note
 *  player view point , ray direction, camera forcal plane direction
 */
static int	set_position_and_direction(t_player *player, int x, int y, char direction)
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
 * @brief get player's position
 */
int	init_player(t_map *map, t_player *player)
{
	int	x;
	int	y;
	int	count_player;

	count_player = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player_position(map->data[y][x]) == true)
			{
				if (count_player != 0)
				{
					// syntax error : invalid map
					return (EXIT_FAILURE);
				}
				count_player++;
				if (set_position_and_direction(player, x, y, map->data[y][x])
					!= EXIT_SUCCESS)
					return (EXIT_FAILURE);
				map->data[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	debug_map_data(*map, "parse_map() after");
	return (EXIT_SUCCESS);
}
