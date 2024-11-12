/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 14:41:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_player(int fd, t_player player)
{
	int	original_stdout_fd;

	original_stdout_fd = set_stdout_fd(fd);
	printf("\tview_point.x = [%f]\n", player.view_point.x);
	printf("\tview_point.y = [%f]\n", player.view_point.y);
	printf("\tray_dir.x    = [%f]\n", player.ray_dir.x);
	printf("\tray_dir.y    = [%f]\n", player.ray_dir.y);
	printf("\tcamera_forcal_plane.x = [%f]\n", player.camera_forcal_plane.x);
	printf("\tcamera_forcal_plane.y = [%f]\n", player.camera_forcal_plane.y);
	if (dup2(original_stdout_fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	close(original_stdout_fd);
}

void	debug_frame(t_game *game, const char *msg)
{
	int			fd;
	t_player	player;

	if (IS_DEBUG != true)
		return ;
	fd = game->debug.fd;
	player = game->player;
	ft_dprintf(fd, "\n>>> func debug_frame() ... call by '%s' <<<\n", msg);
	ft_dprintf(fd, "---- player ----\n");
	put_player(fd, player);
	ft_dprintf(fd, "\n\n");
}
