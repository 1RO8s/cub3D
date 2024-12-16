/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_visited.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:14:24 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 03:14:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_visited(int fd, bool **visited, t_map *map)
{
	for (int r = 0; r < map->height; r++)
	{
		for (int c = 0; c < map->width; c++)
		{
			ft_dprintf(fd, "%d", visited[r][c]);
		}
		ft_dprintf(fd, "\n");
	}
}
