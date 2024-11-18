/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_get_rgb_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:36:28 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/18 16:41:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_get_rgb_color(int fd, t_enum_fc type, int rgb[3], const char *msg)
{
	const char	*s[3] = {"r", "g", "b"};
	int			i;

	if (IS_DEBUG != true)
		return ;
	if (type == ENUM_F)
		ft_dprintf(fd, ">>> func debug_get_rgb_color <<< ... call by %s\n", msg);
	ft_dprintf(fd, "\tcolor[%d]", type);
	i = 0;
	while (i < 3)
	{
		ft_dprintf(fd, "\t%s[%d]", s[i], rgb[i]);
		i++;
	}
	ft_dprintf(fd, "\n");
	if (type == ENUM_C)
		ft_dprintf(fd, "\n");
}
