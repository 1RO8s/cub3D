/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:00:59 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 13:01:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx_window(t_game *game)
{
	game->mlx = (void *)mlx_init();
	if (game->mlx == NULL)
		return (EXIT_FAILURE);
	game->win = (void *)mlx_new_window(game->mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (game->win == NULL)
	{
		free(game->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
