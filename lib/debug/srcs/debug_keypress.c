/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:38:07 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 15:29:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_keypress(int fd, t_enum_key keytype, int keycode)
{
	static const char	*msg[ENUM_OTHER + 1] = {
		"Quit cub3d\n",
		"Move forward\n", "Move backword\n",
		"Move left\n", "Move right\n",
		"Rotate left\n", "Rotate right\n",
		"Invalid keycode[%d]\n"};

	if (IS_DEBUG == false)
		return ;
	if (keytype == ENUM_OTHER)
		ft_dprintf(fd, msg[keytype], keycode);
	else
		ft_dprintf(fd, msg[keytype]);
}
