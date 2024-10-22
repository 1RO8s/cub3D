/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 13:06:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_frame(t_game *game)
{
	t_frame	*frame;

	frame = &game->frame;
	frame->map = (t_map *)&game->map;
	frame->img_3d = (t_img *)&game->img_3d;
	frame->texture = (t_texture *)&game->texture;
	frame->player = (t_player *)&game->player;
	frame->keys.move_forward = 0;
	frame->keys.move_backward = 0;
	frame->keys.strafe_left = 0;
	frame->keys.strafe_right = 0;
	frame->keys.rotate_left = 0;
	frame->keys.rotate_right = 0;
}

/**
 * @brief Parse the cub file contents
 */
static int	parse_cubfile(t_game *game, char *file_contents)
{
	if (init_texture(game->mlx, game->texture, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_floor_and_ceiling(game, file_contents) != EXIT_SUCCESS)
	{
		destroy_texture_image(game->mlx, game->texture, 4);
		return (EXIT_FAILURE);
	}
	if (init_map(&game->map, file_contents) != EXIT_SUCCESS)
	{
		destroy_texture_image(game->mlx, game->texture, 4);
		return (EXIT_FAILURE);
	}
	if (init_player(&game->map, &game->player) != EXIT_SUCCESS)
	{
		destroy_texture_image(game->mlx, game->texture, 4);
		free_double_pointer(game->map.data);
		return (EXIT_FAILURE);
	}
	init_frame(game);
	return (EXIT_SUCCESS);
}

int	init_cub_contents(t_game *game, char *filename)
{
	char	*file_contents;
	int		status;

	file_contents = read_cubfile(filename);
	if (file_contents == NULL)
		return (EXIT_FAILURE);
	status = parse_cubfile(game, file_contents);
	free(file_contents);
	if (status != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
