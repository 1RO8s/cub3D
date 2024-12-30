/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotate_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:02:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/21 09:38:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_rotate_left_flag(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
	{
		game->frame.flag = BIT_ROTATE_LEFT;
	}
}
		//debug_keypress(STDOUT_FILENO, ENUM_LEFT, keycode);

void	set_rotate_right_flag(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
	{
		game->frame.flag = BIT_ROTATE_RIGHT;
	}
}
		//debug_keypress(STDOUT_FILENO, ENUM_RIGHT, keycode);
