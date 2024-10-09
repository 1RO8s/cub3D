/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:21:16 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/10 08:12:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_keypress(int fd, const char *msg)
{
	if (IS_DEBUG == false)
		return ;
	ft_dprintf(fd, msg);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	fd;

	fd = STDOUT_FILENO;
	if (keycode == KEY_ESC)
	{
		debug_keypress(fd, "ESC\n");
		exit(0);
	}
	else if (keycode == KEY_W)
		debug_keypress(fd, "Move forward\n");
	else if (keycode == KEY_S)
		debug_keypress(fd, "Move backword\n");
	else if (keycode == KEY_A)
		debug_keypress(fd, "Move left\n");
	else if (keycode == KEY_D)
		debug_keypress(fd, "Move right\n");
	else
		ft_dprintf(fd, "keycode[%d]\n", keycode);
	(void)game;
	return (0);
}
// fd = STDOUT_FILENO -> game->debug.fd ... out to debug.log

void	debug_mouse(int fd, int button, int x, int y)
{
	if (IS_DEBUG == false)
		return ;
	ft_dprintf(fd, "mouse[%d] x[%d] y[%d]\n", button, x, y);
}

int	handle_mouse(int button, int x, int y, t_game *game)
{
	int	fd;

	fd = STDOUT_FILENO;
	debug_mouse(fd, button, x, y);
	(void)game;
	return (0);
}
// fd = STDOUT_FILENO -> game->debug.fd ... out to debug.log
