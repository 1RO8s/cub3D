/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_visited.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:14:24 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 22:36:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_visited(int fd, bool **visited, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			ft_dprintf(fd, "%d", visited[row][col]);
			col++;
		}
		ft_dprintf(fd, "\n");
		row++;
	}
}
