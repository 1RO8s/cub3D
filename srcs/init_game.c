/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:50:44 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 15:40:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_and_free(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img_3d.img);
	mlx_destroy_image(game->mlx, game->img_2d.img);
	free(game->mlx);
	close(game->debug.fd);
}

/**
 * @brief Initialize Cub3d game
 */
int	init_game(t_game *game, int argc, char *argv[])
{
	if (arg_check(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_debug_info(game) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_mlx_window(game) != EXIT_SUCCESS)
	{
		close(game->debug.fd);
		return (EXIT_FAILURE);
	}
	if (init_mlx_image(game) != EXIT_SUCCESS)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		close(game->debug.fd);
		return (EXIT_FAILURE);
	}
	if (init_cub_contents(game, argv[1]) != EXIT_SUCCESS)
	{
		destroy_and_free(game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
