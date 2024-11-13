/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_wall_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:02:39 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/14 02:24:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_wall_slice(int fd,
			double perp_wall_dist, t_wall_slice wall_slice, const char *msg)
{
	char	str[SIZE_DOUBLE_TO_STR];

	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, "\n\n>>> func debug_wall_slice() ... call by '%s' <<<\n", msg);
	double_to_string(perp_wall_dist, str, sizeof(str));
	ft_dprintf(fd, "\tperp_wall_dist = [%s]\n", str);
	ft_dprintf(fd, "---- wall_slice ----\n");
	ft_dprintf(fd, "\tline_height = [%d]\n", wall_slice.line_height);
	ft_dprintf(fd, "\tstart       = [%d]\n", wall_slice.draw_start);
	ft_dprintf(fd, "\tend         = [%d]\n", wall_slice.draw_end);
	ft_dprintf(fd, "\tcolor       = [0x%X]\n", wall_slice.color);
	ft_dprintf(fd, "\n\n");
}
