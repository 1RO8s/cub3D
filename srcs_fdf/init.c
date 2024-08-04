/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:48:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/31 14:03:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	init_color(t_clr *color, int start_color, int end_color)
{
	color->start_r = (start_color >> 16) & 0xFF;
	color->start_g = (start_color >> 8) & 0xFF;
	color->start_b = start_color & 0xFF;
	color->end_r = (end_color >> 16) & 0xFF;
	color->end_g = (end_color >> 8) & 0xFF;
	color->end_b = end_color & 0xFF;
}

static int	less_than(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	init_line(t_line *line, t_wire *screen)
{
	line->px = screen->x0;
	line->py = screen->y0;
	line->dx = ft_abs(screen->x1 - screen->x0);
	line->dy = ft_abs(screen->y1 - screen->y0);
	line->sx = less_than(screen->x0, screen->x1);
	line->sy = less_than(screen->y0, screen->y1);
	line->err = line->dx - line->dy;
}
