/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_backward.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:47:13 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/17 02:02:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_collision_detection_x(char **data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->view_point.x + player->ray_dir.x * player->move_speed);
	y = (int)(player->view_point.y);
	if (data[y][x] == '1')
		return (true);
	return (false);
}

bool	is_collision_detection_y(char **data, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->view_point.x);
	y = (int)(player->view_point.y + player->ray_dir.y * player->move_speed);
	if (data[y][x] == '1')
		return (true);
	return (false);
}

void	move_forward(t_map *map, t_player *player)
{
	if (is_collision_detection_x(map->data, player) == false)
		player->view_point.x += player->ray_dir.x * player->move_speed;
	if (is_collision_detection_y(map->data, player) == false)
		player->view_point.y += player->ray_dir.y * player->move_speed;
}
// reference type_cub3d.h
//typedef struct s_player {
//	t_vector	view_point;
//	t_vector	ray_dir;
//	t_vector	camera_forcal_plane;
//	double		move_speed;
//	double		rotate_speed;
//}	t_player;
