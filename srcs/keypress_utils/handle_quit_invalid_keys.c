/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quit_invalid_keys.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:54 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/05 18:38:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	quit_game(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		debug_keypress(game->debug.fd, ENUM_ESC, keycode);
		end_game(game);
	}
}

void	invalid_key(int keycode, t_game *game)
{
	if (game->frame.flag == 0x00)
		debug_keypress(game->debug.fd, ENUM_OTHER, keycode);
}
