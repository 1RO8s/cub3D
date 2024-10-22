/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:23:51 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/17 18:37:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vector	rotate_vector(t_vector dir, double rotate_rad)
{
	t_vector	new_dir;

	new_dir.x = dir.x * cos(rotate_rad) - dir.y * sin(rotate_rad);
	new_dir.y = dir.x * sin(rotate_rad) + dir.y * cos(rotate_rad);
	return (new_dir);
}

void	rotate_right(t_map *map, t_player *player)
{
	player->ray_dir = rotate_vector(player->ray_dir, player->rotate_speed);
	player->camera_forcal_plane
		= rotate_vector(player->camera_forcal_plane, player->rotate_speed);
	(void)map;
}

void	rotate_left(t_map *map, t_player *player)
{
	player->ray_dir = rotate_vector(player->ray_dir, -player->rotate_speed);
	player->camera_forcal_plane
		= rotate_vector(player->camera_forcal_plane, -player->rotate_speed);
	(void)map;
}
