/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move_strafe_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:42:53 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/15 14:23:53 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_move_forward_flag(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		debug_keypress(STDOUT_FILENO, ENUM_W, keycode);
		game->frame.flag |= BIT_MOVE_FORWARD;
	}
}

void	set_move_backward_flag(int keycode, t_game *game)
{
	if (keycode == KEY_S)
	{
		debug_keypress(STDOUT_FILENO, ENUM_S, keycode);
		game->frame.flag |= BIT_MOVE_BACKWARD;
	}
}

void	set_strafe_left_flag(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		debug_keypress(STDOUT_FILENO, ENUM_A, keycode);
		game->frame.flag |= BIT_STRAFE_LEFT;
	}
}

void	set_strafe_right_flag(int keycode, t_game *game)
{
	if (keycode == KEY_D)
	{
		debug_keypress(STDOUT_FILENO, ENUM_D, keycode);
		game->frame.flag |= BIT_STRAFE_RIGHT;
	}
}
