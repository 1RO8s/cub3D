/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:23:51 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/17 12:08:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_map *map, t_player *player)
{
	double	old_dir_x;
	double old_plane_x;

	// rotate ray_dir
	old_dir_x = player->ray_dir.x;
	player->ray_dir.x =
		player->ray_dir.x * cos(player->rotate_speed) -
		player->ray_dir.y * sin(player->rotate_speed);
	player->ray_dir.y =
		old_dir_x * sin(player->rotate_speed) +
		player->ray_dir.y * cos(player->rotate_speed);
	// rotate camera plane
	old_plane_x = player->camera_forcal_plane.x;
	player->camera_forcal_plane.x =
		player->camera_forcal_plane.x * cos(player->rotate_speed) -
		player->camera_forcal_plane.y * sin(player->rotate_speed);
	player->camera_forcal_plane.y =
		old_plane_x * sin(player->rotate_speed) +
		player->camera_forcal_plane.y * cos(player->rotate_speed);
	(void)map;
}

void	rotate_left(t_map *map, t_player *player)
{
	double old_dir_x;
	double old_plane_x;

	// rotate ray_dir
	old_dir_x = player->ray_dir.x;
	player->ray_dir.x =
		player->ray_dir.x * cos(-player->rotate_speed) -
		player->ray_dir.y * sin(-player->rotate_speed);
	player->ray_dir.y =
		old_dir_x * sin(-player->rotate_speed) +
		player->ray_dir.y * cos(-player->rotate_speed);
	// rotate camera plane
	old_plane_x = player->camera_forcal_plane.x;
	player->camera_forcal_plane.x =
		player->camera_forcal_plane.x * cos(-player->rotate_speed) -
		player->camera_forcal_plane.y * sin(-player->rotate_speed);
	player->camera_forcal_plane.y =
		old_plane_x * sin(-player->rotate_speed) +
		player->camera_forcal_plane.y * cos(-player->rotate_speed);
	(void)map;
}
