/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_debug_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:37:54 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 16:06:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_debug_info(t_game *game)
{
	int	fd;

	fd = open_log(LOG_FILE, O_TRUNC);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (EXIT_FAILURE);
	}
	game->debug.fd = fd;
	game->map.debug = (t_debug *)&game->debug;
	game->img_3d.debug = (t_debug *)&game->debug;
	game->img_2d.debug = (t_debug *)&game->debug;
	return (EXIT_SUCCESS);
}
