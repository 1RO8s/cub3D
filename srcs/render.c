/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:57:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/10 00:48:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draw the 3D perspective
static void draw_3d_view(t_game *game) {
    // Implement raycasting and draw the 3D view to game->img_3d
    // This part involves calculating the distance to walls and rendering vertical strips
    int				w;
	int				x;
	t_ray_cast		ray_cast;
	t_wall_slice	wall_slice;

	w = WIN_WIDTH / 2;
	x = 0;
	while (x < w)
	{
		init_ray(&ray_cast, &game->player, x);
		debug_ray_cast(ray_cast, "draw_3d_view");// debug
		perform_dda(&ray_cast, &game->map, &game->player);
		set_wall_slice(&wall_slice, &ray_cast);
        draw_vertical_line(&game->img_3d, x, &wall_slice);
		x++;
    }
}

// Draw the 2D top-down map
static void	draw_2d_map(t_game *game) {
	draw_2d_wall(&game->map, &game->img_2d);
	draw_2d_player(&game->img_2d, &game->player);
}

// Rendering a single frame
void	render_frame(t_game *game)
{
	draw_3d_view(game);
	draw_2d_map(game);
	// Draw the 3D image on the left
	mlx_put_image_to_window(game->mlx, game->win, game->img_3d.img, 0, 0);
	// Draw the 2D image on the right
	mlx_put_image_to_window(game->mlx, game->win, game->img_2d.img, WIN_WIDTH / 2, 0);
}
