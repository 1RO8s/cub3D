/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:31:14 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/13 10:36:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	init_plot(t_plot *plot, t_line *line)
{
	plot->px = line->x_start;
	plot->py = line->y_start;
	plot->dx = ft_abs(line->x_end - line->x_start);
	plot->dy = ft_abs(line->y_end - line->y_start);
	plot->sx = less_than(line->x_start, line->x_end);
	plot->sy = less_than(line->y_start, line->y_end);
	plot->err = plot->dx - plot->dy;
}
