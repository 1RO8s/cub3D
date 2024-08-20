/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 02:59:44 by hnagasak          #+#    #+#             */
/*   Updated: 2024/08/11 04:54:19 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>
#include <math.h>

void	print_map_info(t_game *game)
{
	int	i;
	double degree;
	degree = atan2(game->dir.y, game->dir.x) * 180 / M_PI;
	printf("game->pos.x: %f game->pos.y: %f\n", game->pos.x, game->pos.y);
	printf("game->dir.x: %f game->dir.y: %f\n", game->dir.x, game->dir.y);
	printf("degree: %f\n", degree);
	printf("game->north: %s\n", game->north);
	printf("game->south: %s\n", game->south);
	printf("game->west: %s\n", game->west);
	printf("game->east: %s\n", game->east);
	printf("game->floor: %x\n", game->floor);
	printf("game->ceiling: %x\n", game->ceiling);
	printf("game->map:\n");
	i = 0;
	while (game->map[i] != NULL)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	printf("--------------------\n");
}
