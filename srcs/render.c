/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:57:48 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/15 14:05:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_player(t_game *game)
{
	static t_moving_player	func[1] = {
		move_forward};
//	static t_moving_player	func[6] = {
//		move_forward, move_backward,
//		strafe_left, strafe_right,
//		rotate_left, rotate_right};
	int	i;

	i = 0;
	while (i < 1)
	{
		if (is_hit_flag(game->frame.flag, 0x01 << i) == true)
			func[i](&game->map, &game->player);
		i++;
	}
	//while (i < 6)
	//{
	//	if (is_hit_flag(game->frame.flag, 0x01 << i) == true)
	//		func[i](&game->map, &game->player);
	//	i++;
	//}
	game->frame.flag = 0;
}

/**
 * @brief Draw the 3D perspective
 *
 * @note
 * Implement raycasting and draw the 3D view to game->img_3d.
 * Involves calculating the distance to walls and rendering vertical strips
 */
static void	draw_3d_view(t_frame *frame)
{
	int							x;
	static t_draw_3d_process	func[5] = {
		init_ray, perform_dda, set_wall_slice, set_texture_x_coordinate,
		draw_vertical_line};
	int							i;

	x = 0;
	while (x < IMG_3D_WIDTH)
	{
		i = 0;
		while (i < 5)
		{
			func[i](frame, x);
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
	update_player(game);
	debug_frame(game, "render_frame()");
	draw_3d_view(&game->frame);
	draw_2d_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_3d.img, 0, 0);
	mlx_put_image_to_window(
		game->mlx, game->win, game->img_2d.img, IMG_3D_WIDTH, 0);
}
