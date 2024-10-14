/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:21:16 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 15:47:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	static t_handle_keypress	func[ENUM_OTHER + 1] = {
		quit_key, move_forward, move_backward,
		move_left, move_right, rotate_left, rotate_right, invalid_key};
	int						i;

	i = 0;
	while (i < ENUM_OTHER + 1)
	{
		if (func[i](keycode, game) == EXIT_SUCCESS)
			break ;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	handle_mouse(int button, int x, int y, t_game *game)
{
	if (IS_DEBUG == false)
		return (EXIT_FAILURE);
	ft_dprintf(STDOUT_FILENO, "mouse[%d] x[%d] y[%d]\n", button, x, y);
	(void)game;
	return (EXIT_SUCCESS);
}
// fd = STDOUT_FILENO -> game->debug.fd ... out to debug.log
