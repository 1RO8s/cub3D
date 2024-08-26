/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:50:44 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/26 14:10:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief initialize the player's position and direction
 */
void initialize_player(t_game *game, int x, int y, char direction)
{
	game->player_x = x + 0.5;
	game->player_y = y + 0.5;

	if (direction == 'N')
	{
	    game->player_dir_x = 0;
	    game->player_dir_y = -1;
	    game->plane_x = 0.66;
	    game->plane_y = 0;
	}
	else if (direction == 'S')
	{
	    game->player_dir_x = 0;
	    game->player_dir_y = 1;
	    game->plane_x = -0.66;
	    game->plane_y = 0;
	}
	else if (direction == 'W')
	{
	    game->player_dir_x = -1;
	    game->player_dir_y = 0;
	    game->plane_x = 0;
	    game->plane_y = -0.66;
	}
	else if (direction == 'E')
	{
	    game->player_dir_x = 1;
	    game->player_dir_y = 0;
	    game->plane_x = 0;
	    game->plane_y = 0.66;
	}
}

static bool	is_player_position(char map_point)
{
	return (map_point == 'N' || map_point == 'S' ||
			map_point == 'W' || map_point == 'E');
}

// Function to parse the map and find the player's position
void parse_map(t_game *game) {
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
            if (is_player_position(game->map[y][x]) == true)
			{
				initialize_player(game, x, y, game->map[y][x]);
				game->map[y][x] = '0';  // Replace the player marker with an empty space
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
	game->map_width = 10;
	game->map_height = 10;
	game->map = (char *[])
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
	parse_map(game);
}
