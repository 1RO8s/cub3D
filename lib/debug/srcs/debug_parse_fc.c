/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse_fc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:11:18 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 03:11:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_parse_fc(int fd, int color[2], const char *msg)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, ">>> func debug_get_rgb_color <<< ... call by %s\n", msg);
	ft_dprintf(fd, "\tF color[%x]\n", color[0]);
	ft_dprintf(fd, "\tC color[%x]\n", color[1]);
}
