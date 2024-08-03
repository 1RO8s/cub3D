/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:47:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/01 10:30:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* -------- Macro -------- */

/*
 * Error message
 */
# define MSG_MLX	"Error: Failed to initialize MiniLibX\n"
# define MSG_WIN	"Error: Failed to create a window\n"
# define MSG_MAP	"Error: Unmatched number of columns elements in Map file\n"

/*
 * Error number
 */
# define ERR_MLX	0	// mlx_init() faile
# define ERR_WIN	1	// mlx_new_window() faile
# define ERR_MAP	2	// Irregular of 3D MAP data (*.fdf)
# define ERR_NUM	3	// Number of fdf-only error types

/*
 * Window, Image, configuration
 */
# define WIN_WIDTH		1000	// Width of the window
# define WIN_HEIGHT		800		// Height of the window

/*
 * Image configuration
 */
# define IMG_WIDTH		1000	// Width of the window
# define IMG_HEIGHT		800	// Height of the window

/*
 * Wire Frame configuration
 */
# define TILE_SIZE	15			// Size of each tile
# define COLOR		0xFFFFFF	// Color value for points and lines (white)
# define OFFSET_X	500			// 2D screen X coordinate origin
# define OFFSET_Y	300			// 2D screen Y coordinate origin
# define WIN_X		0			// X coordinate to place the image in the window
# define WIN_Y		0			// X coordinate to place the image in the window

/*
 * Other configuration
 */
# define KEY_ESC	53
# define NAME		"fdf"
# define DELIMITERS	" ,"

/*
 * Isometric Projection configuration
 */
# define ANGLE_X 0.523599	// Approximate 30 degrees in radians
# define ANGLE_Y 0.615472	// Approximate 35.26 degrees in radians
# define ANGLE_Z 0.523599	// Approximate 30 degrees in radians

/*
 * Color value
 */
# define C_WHITE	0xffffff
# define C_GREY		0x303030
# define C_RED		0xff0000

/* -------- Structure -------- */

/*
 * Transition the color along the line
 */
typedef struct s_clr
{
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_r;
	int	end_g;
	int	end_b;
}	t_clr;

/*
 * Bresenham's line algorithm -> draw_line()
 *  px,py	Put pixcel in x,y_coordinates
 *  pc		Put pixcel color
 *  dx,dy	Absolute difference in x,y_coordinates
 *  sx,sy	Step direction for x,y (1 or -1)
 *  err		Error term
 */
typedef struct s_line {
	int	px;
	int	py;
	int	pc;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;
}	t_line;

/*
 * Wire Frame Model -> draw_wireframe_model()
 */
typedef struct s_wire {
	int	x0;
	int	y0;
	int	color0;
	int	x1;
	int	y1;
	int	color1;
}	t_wire;

/*
 * Count elements in 3D Map data ( fdf -> t_Map *map)
 */
typedef struct s_Map
{
	int	rows;
	int	cols;
}	t_Map;

/*
 * 3D Coordinate ( fdf -> t_Point3D **points )
 */
typedef struct s_Point3D
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_Point3D;

/*
 * Image data address and associated information
 * 		img				Image instance
 * 		addr			Image data address
 * 		bits_per_pixel	Bits per pixel in the image
 * 		size_line		Size of a single line in bytes
 * 		endian			Endianness of the image data
 */
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

/*
 * FDF main data structure :
 * holds all the information necessary for the fdf to run,
 * so its made easier to be passed by reference by sub-functions
 * 		mlx_ptr		MiniLibX instance
 * 		win_ptr		Window instance
 * 		img_data	Image data
 * 		points		2D array to store 3D Coordinate
 * 		map			3D Map size
 */
typedef struct s_fdf {
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		*img_data;
	t_Point3D	**points;
	t_Map		*map;
}	t_fdf;

/* -------- Functions -------- */

/*
 * Drawing Functions
 */
void	draw_wireframe_model(t_data *data, t_Point3D **points,
			int rows, int cols);
void	draw_line(t_data *data, t_wire *screen);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
 * Importing 3D coordinate data
 */
void	read_map(char *file, t_fdf *fdf);
void	set_points(char *file, t_Point3D **points, int rows, int cols);

/*
 * Error management
 */
void	error_fdf(int error_code);
void	ft_errno_exit(char *cause);
void	ft_perror_exit(char *message);

/*
 * Initialize
 */
void	init_line(t_line *line, t_wire *screen);
void	init_color(t_clr *color, int start_color, int end_color);

#endif
