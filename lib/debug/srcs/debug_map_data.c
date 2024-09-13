/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:44:36 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/13 21:18:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_map_data(t_map map)
{
	int	fd;
	int	y;

	fd = map.debug->fd;
	ft_dprintf(fd, "---- map.data[y][x] ----\n");
	ft_dprintf(fd, "\tmap.height = %d\n", map.height);
	ft_dprintf(fd, "\tmap.widgh = %d\n", map.width);
	ft_dprintf(fd, "\tmap.data[x][y]:\n");
	y = 0;
	while (y < map.height)
	{
		ft_dprintf(fd, "\t\t%s\n", map.data[y]);
		y++;
	}
}
