/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cubfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 15:08:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Parse the cub file contents
 */
int	parse_cubfile(t_game *game, char *file_contents)
{
	if (init_texture(game->mlx, &game->texture, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_floor_and_ceiling(game, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_map(&game->map, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_player(&game->map, &game->player) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
