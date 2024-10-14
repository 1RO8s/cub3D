/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:42:53 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 15:52:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->frame.keys;
	if (keycode == KEY_W)
	{
		debug_keypress(STDOUT_FILENO, ENUM_W, keycode);
		keys->move_forward = 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	move_backward(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->frame.keys;
	if (keycode == KEY_S)
	{
		debug_keypress(STDOUT_FILENO, ENUM_S, keycode);
		keys->move_backward = 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	move_left(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->frame.keys;
	if (keycode == KEY_A)
	{
		debug_keypress(STDOUT_FILENO, ENUM_A, keycode);
		keys->strafe_left = 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	move_right(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->frame.keys;
	if (keycode == KEY_D)
	{
		debug_keypress(STDOUT_FILENO, ENUM_D, keycode);
		keys->strafe_right = 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
