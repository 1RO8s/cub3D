/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:57:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/13 21:54:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw the 3D perspective
 *
 * @note
 * Implement raycasting and draw the 3D view to game->img_3d.
 * Involves calculating the distance to walls and rendering vertical strips
 */
static void	draw_3d_view(t_game *game)
{
	int				w;
	int				x;
	t_ray_cast		ray_cast;
	t_wall_slice	wall_slice;

	w = WIN_WIDTH / 2;
	x = 0;
	while (x < w)
	{
		init_ray(&ray_cast, &game->player, x);
		debug_ray_cast(ray_cast, "draw_3d_view", x);// debug
		perform_dda(&ray_cast, &game->map, &game->player);
		set_wall_slice(&wall_slice, &ray_cast);
		draw_vertical_line(&game->img_3d, x, &wall_slice);
		x++;
	}
	sleep(10);
	exit(0);// debug
}

/**
 * @brief Draw the 2D top-down map
 */
static void	draw_2d_map(t_game *game)
{
	draw_2d_wall(&game->map, &game->img_2d);
	draw_2d_player(&game->img_2d, &game->player);
}

/**
 * @brief Rendering a single frame
 *
 * @note
 *  Draw the 3D image on the left
 *  Draw the 2D image on the right
 */
void	render_frame(t_game *game)
{
	draw_3d_view(game);
	draw_2d_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_3d.img, 0, 0);
	mlx_put_image_to_window(
		game->mlx, game->win, game->img_2d.img, WIN_WIDTH / 2, 0);
}
