/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_wall_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:02:39 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 00:58:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_wall_slice(t_ray_cast *ray_cast, t_wall_slice *wall_slice,
			int line_height, const char *msg)
{
	int	fd;

	if (IS_DEBUG != true)
		return ;
	fd = ray_cast->debug->fd;
	ft_dprintf(fd, "\n\n>>> func debug_wall_slice() ... call by '%s' <<<\n", msg);
	dprintf(fd, "\tperp_wall_dist = [%f]\n", ray_cast->perp_wall_dist);
	ft_dprintf(fd, "---- wall_slice ----\n");
	ft_dprintf(fd, "\tline_height = [%d]\n", line_height);
	ft_dprintf(fd, "\tstart       = [%d]\n", wall_slice->draw_start);
	ft_dprintf(fd, "\tend         = [%d]\n", wall_slice->draw_end);
	ft_dprintf(fd, "\tcolor       = [0x%X]\n", wall_slice->color);
	ft_dprintf(fd, "\n\n");
}
