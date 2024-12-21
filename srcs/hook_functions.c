/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:21:16 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/21 11:10:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	static t_handle_key_press	func[ENUM_OTHER + 1] = {
		quit_game, set_move_forward_flag, set_move_backward_flag,
		set_strafe_left_flag, set_strafe_right_flag,
		set_rotate_left_flag, set_rotate_right_flag, invalid_key};
	int							i;

	i = 0;
	while (i < ENUM_OTHER + 1)
	{
		func[i](keycode, game);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	handle_mouse(int button, int x, int y, t_game *game)
{
	(void)button;
	(void)x;
	(void)y;
	(void)game;
	return (EXIT_SUCCESS);
}
//debug code
//	if (IS_DEBUG == false)
//		return (EXIT_FAILURE);
//	ft_printf("mouse[%d] x[%d] y[%d]\n", button, x, y);
// fd = STDOUT_FILENO -> game->debug.fd ... out to debug.log
