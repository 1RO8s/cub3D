/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:41:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 22:11:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief set line structure for draw_line
 */
//static void	set_line_cordinate(t_line *line, t_player *player)
//{
//	line->x_start = (int)(player->view_point.x * MAP_SCALE);
//	line->y_start = (int)(player->view_point.y * MAP_SCALE);
//	line->color_start = COLOR_RED;
//	line->x_end = line->x_start + player->ray_dir.x * 10 * MAP_SCALE;
//	line->y_end = line->y_start + player->ray_dir.y * 10 * MAP_SCALE;
//	line->color_end = COLOR_RED;
//}

/**
 * @brief Draw player's direction
 */
//static void	draw_players_direction(t_img *img_2d, t_player *player)
//{
//	t_wire	ray_direction;
//
//	set_line_cordinate(&ray_direction, player);
//	draw_line(img_2d, &line);
//}

// Unfinish !!!!
/**
 * @brief Draw player direction on 2D image
 */
void	draw_2d_player(t_img *img_2d, t_player *player)
{
	t_line	line;

	line.x_start = (int)(player->view_point.x * MAP_SCALE);
	line.y_start = (int)(player->view_point.y * MAP_SCALE);
	line.color_start = COLOR_RED;
	line.x_end = line.x_start + player->ray_dir.x * 10 * MAP_SCALE;
	line.y_end = line.y_start + player->ray_dir.y * 10 * MAP_SCALE;
	line.color_end = COLOR_RED;
	draw_line(img_2d, &line);
}
