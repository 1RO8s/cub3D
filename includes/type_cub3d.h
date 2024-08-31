#ifndef TYPE_CUB3D_H
# define TYPE_CUB3D_H

#include <mlx.h>


/******************** draw_line *********************************/
/**
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

typedef struct s_wire {
	int	x0;
	int	y0;
	int	color0;
	int	x1;
	int	y1;
	int	color1;
}	t_wire;

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
 * @brief player info
 */
typedef struct	s_player {
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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

/**
 * @brief raycasting
 */
typedef struct	s_ray {
	double cameraX;       // X-coordinate on the camera plane (-1 to 1)
	double rayDirX;       // Direction of the ray in the X-axis
	double rayDirY;       // Direction of the ray in the Y-axis
	int mapX;             // Current grid position in X
	int mapY;             // Current grid position in Y
	double sideDistX;     // Distance to the next X-side
	double sideDistY;     // Distance to the next Y-side
	double deltaDistX;    // Distance between X-sides
	double deltaDistY;    // Distance between Y-sides
	double perpWallDist;  // Perpendicular distance to the wall
	int stepX;            // Step direction in X (1 or -1)
	int stepY;            // Step direction in Y (1 or -1)
	int hit;              // Whether a wall was hit
	int side;             // Was a NS or EW wall hit?
}	t_ray;

/**
 * @brief wall slice
 */
typedef struct	s_wall_slice {
	int	drawStart;
	int	drawEnd;
	int	color;
}	t_wall_slice;


#endif
