/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:18:16 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/21 09:35:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_game(t_game *game)
{
	ft_printf("quit cub3D\n");
	destroy_texture_image(game->mlx, game->texture,
		BIT_NORTH | BIT_SOUTH | BIT_EAST | BIT_WEST);
	free_double_pointer(game->map.data);
	mlx_destroy_image(game->mlx, game->img_3d.img);
	mlx_destroy_image(game->mlx, game->img_2d.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	exit(0);
}
	//if (game->debug.fd != STDOUT_FILENO)
	//	close(game->debug.fd);

//	free(game->mlx); // don't use : SEGV !!!!

static void	start_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->win, 17, 1L << 17, end_game, game);
	mlx_mouse_hook(game->win, handle_mouse, game);
	mlx_loop_hook(game->mlx, (void *)render_frame, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (init_game(&game, argc, argv) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	start_game(&game);
	return (EXIT_SUCCESS);
}
