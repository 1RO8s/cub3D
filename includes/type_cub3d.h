/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:30:31 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 16:18:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_CUB3D_H
# define TYPE_CUB3D_H

/******************** draw_line *********************************/

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

/******************** common *********************************/

/**
 * @brief debug info
 */
typedef struct s_debug {
	int		fd;
}	t_debug;

/*
 * @brief cordinate of point (int x, int y)
 *
 * @note :
 * map screen
 */
typedef struct s_point {
	int	x;
	int	y;
}	t_point;

/**
 * @brief vector
 */
typedef struct s_vector {
	double	x;
	double	y;
}	t_vector;

/**
 * @brief 3D or 2D or Texture image
 */
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_debug	debug;
}	t_img;

/**
 * @brief texture
 */
typedef struct	s_texture
{
	t_img	img_tex;
	int		width;
	int		height;
	t_debug	debug;
}	t_texture;
// texture[0] ... texture[NORTH]
// texture[1] ... texture[WEST]
// texture[2] ... texture[EAST]
// texture[3] ... texture[SOUTH]

/******************** raycasting *********************************/

/*
 * @brief raycasting
 */
typedef struct s_ray_cast {
	double		camera_plane_x;
	t_vector	ray_dir;
	t_point		grid;
	t_point		step_dir;
	t_vector	next_distance;
	t_vector	delta_distance;
}	t_ray_cast;

typedef struct s_dda {
	int			type_of_grid_line;
	double		perp_wall_dist;
	int			tex_x;
	t_texture	texture;
}	t_dda;

/**
 * @brief wall slice
 */
typedef struct s_wall_slice {
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
}	t_wall_slice;

typedef enum	e_enum_key {
	ENUM_ESC,
	ENUM_W,
	ENUM_S,
	ENUM_A,
	ENUM_D,
	ENUM_LEFT,
	ENUM_RIGHT,
	ENUM_OTHER
}	t_enum_key;

/**
 * @brief keyboard event flag
 */
typedef struct	s_keys {
	int	move_forward;
	int	move_backward;
	int	strafe_left;
	int	strafe_right;
	int	rotate_left;
	int	rotate_right;
}	t_keys;

/******************** main stracture *********************************/

/*
 * @brief ray vector
 */
typedef struct s_player {
	t_vector	view_point;
	t_vector	ray_dir;
	t_vector	camera_forcal_plane;
}	t_player;

/**
 * @brief game map
 */
typedef struct s_map {
	int		width;
	int		height;
	char	**data;
	t_debug	debug;
}	t_map;

typedef enum	e_type_wall {
	NORTH,
	WEST,
	EAST,
	SOURTH
}	t_type_wall;

/**
 * @brief single still image for render_frame
 */
typedef struct s_frame {
	t_ray_cast		ray_cast;
	t_dda			dda;
	t_wall_slice	wall_slice;
	t_player		*player;
	t_keys			keys;
	t_map			*map;
	t_texture		*texture;
	t_img			*img_3d;
	t_debug			debug;
}	t_frame;

/**
 * @brief main game
 */
typedef struct s_game {
	void		*mlx;
	void		*win;
	t_img		img_3d;
	t_img		img_2d;
	t_map		map;
	int			floor_color;
	int			ceiling_color;
	t_player	player;
	t_texture	texture[4];
	t_frame		frame;
	t_debug		debug;
}	t_game;

#endif
