#include "cub3d.h"

int	main(void)
{
	t_game game;

	init_game(&game);

	// Main loop
	//mlx_loop_hook(game.mlx, (void *)render, &game);
	mlx_loop(game.mlx);

	return (0);
}
