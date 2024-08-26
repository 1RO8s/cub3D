#ifndef TYPE_CUB3D_H
# define TYPE_CUB3D_H

#include <mlx.h>

/**
 * @brief RGB color values
 */
typedef struct	s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

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

#endif
