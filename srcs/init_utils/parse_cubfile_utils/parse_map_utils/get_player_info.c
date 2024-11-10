/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/11 04:22:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief initialize the player
 *
 * @note
 *  player view point , ray direction, camera forcal plane direction
 */
static int	set_position_and_direction(
				t_player *player, t_point grid, char direction)
{
	player->view_point.x = grid.x + 0.5;
	player->view_point.y = grid.y + 0.5;
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

bool	is_valid_char(char map_point)
{
	return (map_point == '1' || map_point == '0' || map_point == ' ');
}

static int	find_player_and_set(
				char **data, t_point grid, t_parse *parse, t_player *player)
{
	if (is_player_position(data[grid.y][grid.x]) == true)
	{
		if ((parse->flag & BIT_PLAYER) > 0x00)
		{
			dprintf(STDERR_FILENO, "%s%s", ERR_PROMPT, EMSG_MAP_PLAYER_MULTI);
			return (EXIT_FAILURE);
		}
		parse->flag |= BIT_PLAYER;
		parse->player_grid = grid;// nesessary?
		if (set_position_and_direction(player, grid, data[grid.y][grid.x])
			!= EXIT_SUCCESS)
			return (EXIT_FAILURE);
		data[grid.y][grid.x] = '0';
	}
	else
	{
		if (is_valid_char(data[grid.y][grid.x]) != true)
		{
			dprintf(STDERR_FILENO, "%s%s", ERR_PROMPT, EMSG_MAP_CHAR);
			dprintf(STDERR_FILENO, ": \"%c\"\n", data[grid.y][grid.x]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief get player's position
 */
int	get_player_info(const char *line, t_parse *parse)
{
	t_point	grid;
	t_map	*map;
	t_player	*player;

	(void)line;
	map = &parse->game->map;
	player = &parse->game->player;
	grid.y = 0;
	while (grid.y < map->height)
	{
		grid.x = 0;
		while (grid.x < map->width)
		{
			if (find_player_and_set(map->data, grid, parse, player)
				!= EXIT_SUCCESS)
				return (EXIT_FAILURE);
			grid.x++;
		}
		grid.y++;
	}
	//if ((parse->flag & BIT_PLAYER) > 0x00)// may be ...
	//{
	//	dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_MAP_PLAYER_MISS);
	//	return (EXIT_FAILURE);
	//}
	player->move_speed = MOVE_SPEED;
	player->rotate_speed = ROTATE_SPEED;
	debug_map_data(*map, "get_player_info()");
	debug_player(map->debug.fd, *player, "get_player_info()");
	return (EXIT_SUCCESS);
}
