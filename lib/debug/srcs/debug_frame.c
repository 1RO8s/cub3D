/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/01 02:45:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_frame(t_game *game, const char *msg)
{
	int			fd;
	t_player	player;

	if (IS_DEBUG != true)
		return ;
	fd = game->debug.fd;
	player = game->player;
	dprintf(fd, "\n>>> func debug_frame() ... call by '%s' <<<\n", msg);
	dprintf(fd, "---- player ----\n");
	dprintf(fd, "\tview_point.x = [%f]\n", player.view_point.x);
	dprintf(fd, "\tview_point.y = [%f]\n", player.view_point.y);
	dprintf(fd, "\tray_dir.x    = [%f]\n", player.ray_dir.x);
	dprintf(fd, "\tray_dir.y    = [%f]\n", player.ray_dir.y);
	dprintf(fd, "\tcamera_forcal_plane.x = [%f]\n", player.camera_forcal_plane.x);
	dprintf(fd, "\tcamera_forcal_plane.y = [%f]\n", player.camera_forcal_plane.y);
	dprintf(fd, "\n\n");
}
