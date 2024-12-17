/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_and_set.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:27:33 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/18 02:12:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief initialize the player
 *
 * @note
 *  player view point , ray direction, camera forcal plane direction
 */
static void	set_position_and_direction(
				t_player *player, t_point grid, char direction)
{
	player->view_point.x = grid.x + 0.5;
	player->view_point.y = grid.y + 0.5;
	set_direction(direction, player);
}

/**
 * @brief check the player position
 */
static bool	is_player_position(char map_point)
{
	return (map_point == 'N' || map_point == 'S'
		|| map_point == 'W' || map_point == 'E');
}

bool	is_valid_char(char map_point)
{
	return (map_point == '1' || map_point == '0' || map_point == ' ');
}

int	find_player_and_set(
				char **data, t_point grid, t_parse *parse, t_player *player)
{
	if (is_player_position(data[grid.y][grid.x]) == true)
	{
		if ((parse->flag & BIT_PLAYER) > 0x00)
		{
			ft_eprintf("%s%s",
				ERR_PROMPT, EMSG_MAP_PLAYER_MULTI);
			return (EXIT_FAILURE);
		}
		parse->flag |= BIT_PLAYER;
		parse->player_grid = grid;
		set_position_and_direction(player, grid, data[grid.y][grid.x]);
		data[grid.y][grid.x] = '0';
	}
	else
	{
		if (is_valid_char(data[grid.y][grid.x]) != true)
		{
			ft_eprintf("%s%s", ERR_PROMPT, EMSG_MAP_CHAR);
			ft_eprintf(": \"%c\"\n", data[grid.y][grid.x]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
