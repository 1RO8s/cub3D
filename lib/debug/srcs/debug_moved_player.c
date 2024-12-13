/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_moved_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:26:32 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/14 02:51:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_moved_player(t_game *game)
{
	int			fd;
	t_vector	view_point;
	t_vector	ray_dir;
	char		str[SIZE_DOUBLE_TO_STR];

	if (IS_DEBUG != true || game->frame.flag == 0x00)
		return ;
	fd = STDOUT_FILENO;
	view_point = game->player.view_point;
	ray_dir = game->player.ray_dir;
	double_to_string(view_point.x, str, sizeof(str));
	ft_dprintf(fd, "moved player=<%s, ", str);
	double_to_string(view_point.y, str, sizeof(str));
	ft_dprintf(fd, "%s> ", str);
	double_to_string(ray_dir.x, str, sizeof(str));
	ft_dprintf(fd, "ray_dir=<%s, ", str);
	double_to_string(ray_dir.y, str, sizeof(str));
	ft_dprintf(fd, "%s>\n", str);
}
