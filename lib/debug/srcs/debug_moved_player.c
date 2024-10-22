/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_moved_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:26:32 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/20 02:31:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_moved_player(t_game *game)
{
	int			fd;
	t_vector	view_point;
	t_vector	ray_dir;

	if (IS_DEBUG != true || game->frame.flag == 0x00)
		return ;
	fd = STDOUT_FILENO;
	view_point = game->player.view_point;
	ray_dir = game->player.ray_dir;
	dprintf(fd,
		"moved player=<%f, %f> ray_dir=<%f, %f>\n",
		view_point.x, view_point.y, ray_dir.x, ray_dir.y);
}
