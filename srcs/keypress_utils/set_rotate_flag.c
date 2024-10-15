/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotate_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:02:06 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/15 14:12:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_rotate_left_flag(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
	{
		debug_keypress(STDOUT_FILENO, ENUM_LEFT, keycode);
		game->frame.flag = BIT_ROTATE_LEFT;
		//return (EXIT_SUCCESS);
	}
	//return (EXIT_FAILURE);
}

void	set_rotate_right_flag(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
	{
		debug_keypress(STDOUT_FILENO, ENUM_RIGHT, keycode);
		game->frame.flag = BIT_ROTATE_RIGHT;
		//return (EXIT_SUCCESS);
	}
	//return (EXIT_FAILURE);
}

