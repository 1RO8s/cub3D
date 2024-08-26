/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:41:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/26 15:03:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_2d_player(t_game *game)
{
	// Draw the player
	int	player_x;
	int	player_y;

	player_x = game->player_x * MAP_SCALE;
	player_y = game->player_y * MAP_SCALE;
	// Red for player
	my_mlx_pixel_put(&game->img_2d, player_x, player_y, 0xFF0000);

	// Draw the player's direction
	int	dir_line_x;
	int	dir_line_y;

	dir_line_x = player_x + game->player_dir_x * 10 * MAP_SCALE;
	dir_line_y = player_y + game->player_dir_y * 10 * MAP_SCALE;
	// Bresenham's line algorithm or any simple line drawing algorithm to draw the direction
}
