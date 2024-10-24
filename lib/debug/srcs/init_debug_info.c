/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_debug_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:37:54 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/13 05:31:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_debug_info(t_game *game)
{
	int	fd;
	int	i;

	fd = open_log(LOG_FILE, O_TRUNC);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (EXIT_FAILURE);
	}
	game->debug.fd = fd;
	game->debug.game = game;
	game->map.debug = game->debug;
	game->img_3d.debug = game->debug;
	game->img_2d.debug = game->debug;
	game->frame.debug = game->debug;
	i = 0;
	while (i < 4)
	{
		game->texture[i].debug = game->debug;
		i++;
	}
	return (EXIT_SUCCESS);
}
