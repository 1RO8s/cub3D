/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/18 02:13:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_map_grid(t_map *map, t_player *player, t_parse *parse)
{
	t_point		grid;

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
	return (EXIT_SUCCESS);
}

/**
 * @brief get player's position
 */
int	get_player_info(const char *line, t_parse *parse)
{
	t_map		*map;
	t_player	*player;

	(void)line;
	map = &parse->game->map;
	player = &parse->game->player;
	if (process_map_grid(map, player, parse) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if ((parse->flag & BIT_PLAYER) == 0x00)
	{
		ft_eprintf("%s%s\n", ERR_PROMPT, EMSG_MAP_PLAYER_MISS);
		return (EXIT_FAILURE);
	}
	player->move_speed = MOVE_SPEED;
	player->rotate_speed = ROTATE_SPEED;
	debug_map_data(*map, "get_player_info()");
	debug_player(map->debug.fd, *player, "get_player_info()");
	return (EXIT_SUCCESS);
}
