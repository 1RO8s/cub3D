/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:08:46 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/14 02:29:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_player(int fd, t_player player)
{
	char	str[SIZE_DOUBLE_TO_STR];

	double_to_string(player.view_point.x, str, sizeof(str));
	ft_dprintf(fd, "\tview_point.x = [%s]\n", str);
	double_to_string(player.view_point.y, str, sizeof(str));
	ft_dprintf(fd, "\tview_point.y = [%s]\n", str);
	double_to_string(player.ray_dir.x, str, sizeof(str));
	ft_dprintf(fd, "\tray_dir.x    = [%s]\n", str);
	double_to_string(player.ray_dir.y, str, sizeof(str));
	ft_dprintf(fd, "\tray_dir.y    = [%s]\n", str);
	double_to_string(player.camera_forcal_plane.x, str, sizeof(str));
	ft_dprintf(fd, "\tcamera_forcal_plane.x = [%s]\n", str);
	double_to_string(player.camera_forcal_plane.y, str, sizeof(str));
	ft_dprintf(fd, "\tcamera_forcal_plane.y = [%s]\n", str);
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
