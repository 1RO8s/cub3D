/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:30:31 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/12 22:20:46 by kamitsui         ###   ########.fr       */
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
 * @brief 3D or 2D image
 */
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
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
 */
typedef struct	s_ray_cast {
	double		camera_plane_x;
	t_vector	ray_dir;
	t_point		grid;
	t_vector	next_side;
	t_vector	delta_distance;
	double perpWallDist;  // Perpendicular distance to the wall
	t_point		step_dir;
	int hit;              // Whether a wall was hit
	int side;             // Was a NS or EW wall hit?
}	t_ray_cast;
//	X-coordinate on the camera plane (-1 to 1)
//	double rayDirX;       // Direction of the ray in the X-axis
//	double rayDirY;       // Direction of the ray in the Y-axis
//	int mapX;             // Current grid position in X
//	int mapY;             // Current grid position in Y
//	double sideDistX;     // Distance to the next X-side
//	double sideDistY;     // Distance to the next Y-side
//	double deltaDistX;    // Distance between X-sides
//	double deltaDistY;    // Distance between Y-sides
//	int stepX;            // Step direction in X (1 or -1)
//	int stepY;            // Step direction in Y (1 or -1)

/**
 * @brief wall slice
 */
typedef struct	s_wall_slice {
	int	drawStart;
	int	drawEnd;
	int	color;
}	t_wall_slice;


#endif
