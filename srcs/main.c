/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:18:16 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/13 21:24:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_game *game)
{
	mlx_loop_hook(game->mlx, (void *)&render_frame, game);
	//mlx_hook(game->win, 2, 1L<<0, &handle_keypress, game);  // Key press
	//mlx_hook(game->win, 17, 1L<<17, &handle_exit, game);    // Window close
	mlx_loop(game->mlx);
}

void	end_game(t_game *game)
{
	// free game(mlx, window, img_3d, img_2d, map.data)
	// close fd ... debug.log
	if (close(game->debug.fd) == -1)
		exit(1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (init_game(&game, argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	start_game(&game);
	end_game(&game);
	return (0);
}
