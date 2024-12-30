/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move_strafe_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:42:53 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/21 09:38:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_move_forward_flag(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->frame.flag |= BIT_MOVE_FORWARD;
	}
}
	//	debug_keypress(STDOUT_FILENO, ENUM_W, keycode);

void	set_move_backward_flag(int keycode, t_game *game)
{
	if (keycode == KEY_S)
	{
		game->frame.flag |= BIT_MOVE_BACKWARD;
	}
}
	//	debug_keypress(STDOUT_FILENO, ENUM_S, keycode);

void	set_strafe_left_flag(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		game->frame.flag |= BIT_STRAFE_LEFT;
	}
}
	//	debug_keypress(STDOUT_FILENO, ENUM_A, keycode);

void	set_strafe_right_flag(int keycode, t_game *game)
{
	if (keycode == KEY_D)
	{
		game->frame.flag |= BIT_STRAFE_RIGHT;
	}
}
	//	debug_keypress(STDOUT_FILENO, ENUM_D, keycode);
