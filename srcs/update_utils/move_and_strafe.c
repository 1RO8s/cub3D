/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_strafe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:47:13 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/17 11:23:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_map *map, t_player *player)
{
	t_vector	move_amount;

	move_amount.x = player->ray_dir.x * player->move_speed;
	if (is_collision_detection_x(
			map->data, player->view_point, move_amount.x) == false)
		player->view_point.x += move_amount.x;
	move_amount.y = player->ray_dir.y * player->move_speed;
	if (is_collision_detection_y(
			map->data, player->view_point, move_amount.y) == false)
		player->view_point.y += move_amount.y;
}

void	move_backward(t_map *map, t_player *player)
{
	t_vector	move_amount;

	move_amount.x = - (player->ray_dir.x * player->move_speed);
	if (is_collision_detection_x(
			map->data, player->view_point, move_amount.x) == false)
		player->view_point.x += move_amount.x;
	move_amount.y = - (player->ray_dir.y * player->move_speed);
	if (is_collision_detection_y(
			map->data, player->view_point, move_amount.y) == false)
		player->view_point.y += move_amount.y;
}

void	strafe_left(t_map *map, t_player *player)
{
	t_vector	move_amount;

	move_amount.x = - (player->camera_forcal_plane.x * player->move_speed);
	if (is_collision_detection_x(
			map->data, player->view_point, move_amount.x) == false)
		player->view_point.x += move_amount.x;
	move_amount.y = - (player->camera_forcal_plane.y * player->move_speed);
	if (is_collision_detection_y(
			map->data, player->view_point, move_amount.y) == false)
		player->view_point.y += move_amount.y;
}

void	strafe_right(t_map *map, t_player *player)
{
	t_vector	move_amount;

	move_amount.x = player->camera_forcal_plane.x * player->move_speed;
	if (is_collision_detection_x(
			map->data, player->view_point, move_amount.x) == false)
		player->view_point.x += move_amount.x;
	move_amount.y = player->camera_forcal_plane.y * player->move_speed;
	if (is_collision_detection_y(
			map->data, player->view_point, move_amount.y) == false)
		player->view_point.y += move_amount.y;
}
