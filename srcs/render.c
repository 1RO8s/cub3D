/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:57:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/11 21:19:17 by kamitsui         ###   ########.fr       */
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
	int							w;
	int							x;
	t_one_shot_3d				one_shot_3d;
	static t_draw_3d_process	func[4] = {
		init_ray, perform_dda, set_wall_slice, draw_vertical_line};
	int							i;

	w = IMG_3D_WIDTH;
	x = 0;
	one_shot_3d.map = (t_map)game->map;
	one_shot_3d.img_3d = (t_img)game->img_3d;
	one_shot_3d.texture = (t_texture *)game->texture;
	one_shot_3d.player = (t_player)game->player;
	one_shot_3d.debug = (t_debug)game->debug;
	while (x < w)
	{
		i = 0;
		while (i < 4)
		{
			func[i](&one_shot_3d, x);
			i++;
		}
		x++;
	}
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
	debug_frame(game, "render_frame()");
	draw_3d_view(game);
	draw_2d_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_3d.img, 0, 0);
	mlx_put_image_to_window(
		game->mlx, game->win, game->img_2d.img, IMG_3D_WIDTH, 0);
}
