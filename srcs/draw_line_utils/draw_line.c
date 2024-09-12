/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:34:59 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 22:23:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// propo is: Proportion of moving points to line span
static int	transition_color(int start, int end, int move_point, t_clr *color)
{
	int	span;
	int	propo;
	int	tr_r;
	int	tr_g;
	int	tr_b;

	span = end - start;
	propo = (move_point - start) * 255 / span;
	tr_r = color->start_r + ((color->end_r - color->start_r) * propo) / 255;
	tr_g = color->start_g + ((color->end_g - color->start_g) * propo) / 255;
	tr_b = color->start_b + ((color->end_b - color->start_b) * propo) / 255;
	return ((tr_r << 16) | (tr_g << 8) | tr_b);
}

static int	get_current_color(t_plot *plot, t_line *line, t_clr *color)
{
	int	start;
	int	end;
	int	move_point;

	if (plot->dx > 0)
	{
		start = line->x0;
		end = line->x1;
		move_point = plot->px;
	}
	else
	{
		start = line->y0;
		end = line->y1;
		move_point = plot->py;
	}
	return (transition_color(start, end, move_point, color));
}

//#include "ft_printf.h"
//void	debug_line(int x0, int y0, int color0,
//		int x1, int y1, int color1)
//{
//	ft_printf("\n\n---- draw_line ----  start -> end\n");
//	ft_printf("start\tx0:%d y0:%d color0:%X\n", x0, y0, color0);
//	ft_printf("end  \tx1:%d y1:%d color1:%X\n", x1, y1, color1);
//}
//
//void	debug_count(int px, int py, int pc)
//{
//	static int i = 0;
//	ft_printf("draw_loop : %d\tpx:%d\tpy:%d\tpc:%X\n", i++, px, py, pc);
//}
//	debug_line(line->x0, line->y0, line->color0,
//	line->x1, line->y1, line->color1);
//		debug_count(plot->px, plot->py, plot->pc);

static void	draw_loop(t_plot *plot, t_line *line, t_clr *color, t_img *img)
{
	while (1)
	{
		if (plot->px >= IMG_WIDTH || plot->px <= 0
			|| plot->py >= IMG_HEIGHT || plot->py <= 0)
			break ;
		plot->pc = get_current_color(plot, line, color);
		my_mlx_pixel_put(img, plot->px, plot->py, plot->pc);
		if (plot->px == line->x1 && plot->py == line->y1)
			break ;
		plot->err2 = 2 * plot->err;
		if (plot->err2 > -plot->dy)
		{
			plot->err -= plot->dy;
			plot->px += plot->sx;
		}
		if (plot->err2 < plot->dx)
		{
			plot->err += plot->dx;
			plot->py += plot->sy;
		}
	}
}

// memo : develop unfinished
// Bresenham's line algorithm
void	draw_line(t_img *img, t_line *line)
{
	t_plot	plot;
	t_clr	color;

	init_plot(&plot, line);
	init_color(&color, line->color0, line->color1);
	draw_loop(&plot, line, &color, img);
}
