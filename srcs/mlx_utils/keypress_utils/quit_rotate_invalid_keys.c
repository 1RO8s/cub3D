/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_rotate_invalid_keys.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:54 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 15:54:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		debug_keypress(STDOUT_FILENO, ENUM_ESC, keycode);
		exit (EXIT_SUCCESS);
	}
	(void)game;
	return (EXIT_FAILURE);
}

int	rotate_left(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->frame.keys;
	if (keycode == KEY_LEFT)
	{
		debug_keypress(STDOUT_FILENO, ENUM_LEFT, keycode);
		keys->rotate_left = 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	rotate_right(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->frame.keys;
	if (keycode == KEY_RIGHT)
	{
		debug_keypress(STDOUT_FILENO, ENUM_RIGHT, keycode);
		keys->rotate_right = 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	invalid_key(int keycode, t_game *game)
{
	debug_keypress(STDOUT_FILENO, ENUM_OTHER, keycode);
	(void)game;
	return (EXIT_SUCCESS);
}
