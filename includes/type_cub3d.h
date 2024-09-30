/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:30:31 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 16:10:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_CUB3D_H
# define TYPE_CUB3D_H

/******************** draw_line *********************************/

/*
 * @brief RGB color values
 */
typedef struct	s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_clr
{
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_r;
	int	end_g;
	int	end_b;
}	t_clr;

typedef struct s_plot {
	int	px;
	int	py;
	int	pc;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;
}	t_plot;

typedef struct s_line {
	int	x_start;
	int	y_start;
	int	color_start;
	int	x_end;
	int	y_end;
	int	color_end;
}	t_line;

/******************** main stracture *********************************/

/**
 * @brief debug info
 */
typedef struct s_debug {
	int		fd;
}	t_debug;

/**
 * @brief 3D or 2D image
 */
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_debug	*debug;
}	t_img;

/**
 * @brief vector
 */
typedef struct	s_vector {
	double	x;
	double	y;
}	t_vector;

/*
 * @brief ray vector
 */
typedef struct	s_player {
	t_vector	view_point;
	t_vector	ray_dir;
	t_vector	camera_forcal_plane;
}	t_player;

/**
 * @brief game map
 */
typedef struct	s_map {
	int		width;
	int		height;
	char	**data;
	t_debug	*debug;
}	t_map;

/**
 * @brief main game
 */
typedef struct	s_game {
	void		*mlx;
	void		*win;
	t_img		img_3d;
	t_img		img_2d;
	t_map		map;
	t_color		ceiling_color;
	t_color		floor_color;
	t_player	player;
	t_debug		debug;
}	t_game;

/******************** raycasting *********************************/

/*
 * @brief cordinate of point (int x, int y)
 *
 * @note :
 * map screen 
 */
typedef struct	s_point {
	int	x;
	int	y;
}	t_point;

/**
 * @brief raycasting
 *
 * @member
 * camera_plane_x : normalized (-1 ~ 1) on the camera plane
 * ray_dir : directon of x coordinate on the camera plane
 * grid : map cordinate (int value) ... map->data[grid.y][grid.x]
 * step_dir : direction for next grid ... -1 or 1 (both step_dir.x, step_dir.y)
 * next_distance : distance to next x-side(HORIZONTAL_LINE) or y-side(VERTICAL_LINE)
 * delta_distance : used to incrementally move the ray across the grid
 * type_of_grid_line ... 0:ON_VERTICAL_LINE 1:ON_HORIZONTAL_LINE -1:START_POINT
 * perp_wall_dist : Perpendicular distance to the wall
 */
typedef struct	s_ray_cast {
	double		camera_plane_x;
	t_vector	ray_dir;
	t_point		grid;
	t_point		step_dir;
	t_vector	next_distance;
	t_vector	delta_distance;
}	t_ray_cast;

typedef struct	s_dda {
	int 		type_of_grid_line;
	double		perp_wall_dist;
}	t_dda;

/**
 * @brief wall slice
 */
typedef struct	s_wall_slice {
	int	draw_start;
	int	draw_end;
	int	color;
}	t_wall_slice;

typedef struct	s_one_shot_3d {
	t_player		player;
	t_map			map;
	t_ray_cast		ray_cast;
	t_dda			dda;
	t_wall_slice	wall_slice;
	t_img			img_3d;
	t_debug			debug;
}	t_one_shot_3d;

#endif
