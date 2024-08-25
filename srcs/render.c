/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:57:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/26 01:59:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to draw the 3D perspective
void draw_3d_view(t_game *game) {
    // Implement raycasting and draw the 3D view to game->img_3d
    // This part involves calculating the distance to walls and rendering vertical strips
}

// Function to draw the 2D top-down map
void draw_2d_map(t_game *game) {
    int x, y;

    // Draw the map
    for (y = 0; y < game->map_height; y++) {
        for (x = 0; x < game->map_width; x++) {
            if (game->map[y][x] == '1') {
                int start_x = x * MAP_SCALE;
                int start_y = y * MAP_SCALE;
                for (int i = 0; i < MAP_SCALE; i++) {
                    for (int j = 0; j < MAP_SCALE; j++) {
                        my_mlx_pixel_put(&game->img_2d, start_x + i, start_y + j, 0xFFFFFF); // White for walls
                    }
                }
            }
        }
    }

    // Draw the player
    int player_x = game->player_x * MAP_SCALE;
    int player_y = game->player_y * MAP_SCALE;
    my_mlx_pixel_put(&game->img_2d, player_x, player_y, 0xFF0000); // Red for player

    // Draw the player's direction
    int dir_line_x = player_x + game->player_dir_x * 10 * MAP_SCALE;
    int dir_line_y = player_y + game->player_dir_y * 10 * MAP_SCALE;
    // Bresenham's line algorithm or any simple line drawing algorithm to draw the direction
}

// Function to render both views
void render(t_game *game)
{
    draw_3d_view(game);
    draw_2d_map(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img_3d.img, 0, 0);  // Draw the 3D image on the left
    mlx_put_image_to_window(game->mlx, game->win, game->img_2d.img, WIN_WIDTH / 2, 0);  // Draw the 2D image on the right
}
