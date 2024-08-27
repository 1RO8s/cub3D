/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:50:44 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/27 19:16:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief initialize the player's position and direction
 */
void initialize_player(t_player *player, int x, int y, char direction)
{
	player->x = x + 0.5;
	player->y = y + 0.5;

	if (direction == 'N')
	{
	    player->dir_x = 0;
	    player->dir_y = -1;
	    player->plane_x = 0.66;
	    player->plane_y = 0;
	}
	else if (direction == 'S')
	{
	    player->dir_x = 0;
	    player->dir_y = 1;
	    player->plane_x = -0.66;
	    player->plane_y = 0;
	}
	else if (direction == 'W')
	{
	    player->dir_x = -1;
	    player->dir_y = 0;
	    player->plane_x = 0;
	    player->plane_y = -0.66;
	}
	else if (direction == 'E')
	{
	    player->dir_x = 1;
	    player->dir_y = 0;
	    player->plane_x = 0;
	    player->plane_y = 0.66;
	}
}

static bool	is_player_position(char map_point)
{
	return (map_point == 'N' || map_point == 'S' ||
			map_point == 'W' || map_point == 'E');
}

// Function to parse the map and find the player's position
void parse_map(t_map *map, t_player *player) {
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
				map->data[y][x] = '0';  // Replace the player marker with an empty space
				return;  // Assuming only one player, we can exit after finding it
			}
			x++;
		}
		y++;
	}
}

void init_game(t_game *game)
{
	// Initialize the MiniLibX window
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");

	// Initialize the 3D image
	game->img_3d.img = mlx_new_image(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT);
	game->img_3d.addr = mlx_get_data_addr(game->img_3d.img, &game->img_3d.bpp, &game->img_3d.line_length, &game->img_3d.endian);

	// Initialize the 2D image
	game->img_2d.img = mlx_new_image(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT);
	game->img_2d.addr = mlx_get_data_addr(game->img_2d.img, &game->img_2d.bpp, &game->img_2d.line_length, &game->img_2d.endian);

	// Load the map data
	game->map.width = 10;
	game->map.height = 10;
	game->map.data = (char *[])
	{
		"1111111111",
		"1000000001",
		"1000000001",
		"1000N00001",
		"1000110001",
		"1000000001",
		"1000110001",
		"1000000001",
		"1000000001",
		"1111111111"
	};
	
	// Parse the map to find the player's initial position and direction
	parse_map(&game->map, &game->player);
}
