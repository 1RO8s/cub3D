/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_backward.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:47:13 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/15 14:16:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_cub3d.h"

void	move_forward(t_map *map, t_player *player)
{
	// Collision Detection
	//if (game->map[(int)(player->y)][(int)(player->x + player->dir_x * player->move_speed)] == '0')
		player->view_point.x += player->ray_dir.x * player->move_speed;
	// Collision Detection
	//if (game->map[(int)(player->y + player->dir_y * player->move_speed)][(int)(player->x)] == '0')
		player->view_point.y += player->ray_dir.y * player->move_speed;
	(void)map;
}
// reference type_cub3d.h
//typedef struct s_player {
//	t_vector	view_point;
//	t_vector	ray_dir;
//	t_vector	camera_forcal_plane;
//	double		move_speed;
//	double		rotate_speed;
//}	t_player;
