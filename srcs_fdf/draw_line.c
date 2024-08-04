/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:35:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/01 10:51:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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

static int	get_current_color(t_line *line, t_wire *screen, t_clr *color)
{
	int	start;
	int	end;
	int	move_point;

	if (line->dx > 0)
	{
		start = screen->x0;
		end = screen->x1;
		move_point = line->px;
	}
	else
	{
		start = screen->y0;
		end = screen->y1;
		move_point = line->py;
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
//	debug_line(screen->x0, screen->y0, screen->color0,
//	screen->x1, screen->y1, screen->color1);
//		debug_count(line->px, line->py, line->pc);

static void	draw_loop(t_line *line, t_wire *screen, t_clr *color, t_data *data)
{
	while (1)
	{
		if (line->px >= IMG_WIDTH || line->px <= 0
			|| line->py >= IMG_HEIGHT || line->py <= 0)
			break ;
		line->pc = get_current_color(line, screen, color);
		my_mlx_pixel_put(data, line->px, line->py, line->pc);
		if (line->px == screen->x1 && line->py == screen->y1)
			break ;
		line->err2 = 2 * line->err;
		if (line->err2 > -line->dy)
		{
			line->err -= line->dy;
			line->px += line->sx;
		}
		if (line->err2 < line->dx)
		{
			line->err += line->dx;
			line->py += line->sy;
		}
	}
}

// Bresenham's line algorithm
void	draw_line(t_data *data, t_wire *screen)
{
	t_line	line;
	t_clr	color;

	init_line(&line, screen);
	init_color(&color, screen->color0, screen->color1);
	draw_loop(&line, screen, &color, data);
}
