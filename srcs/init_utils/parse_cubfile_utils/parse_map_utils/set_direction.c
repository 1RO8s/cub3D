/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:27:02 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/16 03:03:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north_direction(
	t_vector *ray_dir, t_vector *camera_forcal_plane)
{
	ray_dir->x = 0;
	ray_dir->y = -1;
	camera_forcal_plane->x = 0.66;
	camera_forcal_plane->y = 0;
}

static void	set_south_direction(
	t_vector *ray_dir, t_vector *camera_forcal_plane)
{
	ray_dir->x = 0;
	ray_dir->y = 1;
	camera_forcal_plane->x = -0.66;
	camera_forcal_plane->y = 0;
}

static void	set_west_direction(
	t_vector *ray_dir, t_vector *camera_forcal_plane)
{
	ray_dir->x = -1;
	ray_dir->y = 0;
	camera_forcal_plane->x = 0;
	camera_forcal_plane->y = -0.66;
}

static void	set_east_direction(
	t_vector *ray_dir, t_vector *camera_forcal_plane)
{
	ray_dir->x = 1;
	ray_dir->y = 0;
	camera_forcal_plane->x = 0;
	camera_forcal_plane->y = 0.66;
}

void	set_direction(char direction, t_player *player)
{
	if (direction == 'N')
		set_north_direction(&player->ray_dir, &player->camera_forcal_plane);
	else if (direction == 'S')
		set_south_direction(&player->ray_dir, &player->camera_forcal_plane);
	else if (direction == 'W')
		set_west_direction(&player->ray_dir, &player->camera_forcal_plane);
	else if (direction == 'E')
		set_east_direction(&player->ray_dir, &player->camera_forcal_plane);
}
