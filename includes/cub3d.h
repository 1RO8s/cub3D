/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:19:09 by hnagasak          #+#    #+#             */
/*   Updated: 2024/09/12 16:27:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// -------------- include ---------------
// project specific header files
# include "type_cub3d.h"
# include <mlx.h>


// own libraries
# include "libft.h"
# include "debug_cub3d.h"

// stadard libraries
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

// -------------- define ---------------
// Cub3d game window
# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define MAP_SCALE 4

// Cub3d color
# define COLOR_GREY 0xAAAAAA
# define COLOR_WHITE 0xFFFFFF

// -------------- function prototype ---------------
// main
int		init_game(t_game *game, int argc, char *argv[]);
void	render_frame(t_game *game);

// init_utils
int		read_map(t_map *map, char *file)
void	parse_map(t_map *map, t_player *player);
int		set_direction(char direction, t_player *player);

// 3D
void	init_ray(t_ray_cast *ray_cast, t_player *player, int x);
void	perform_dda(t_ray_cast *ray_cast, t_map *map, t_player *player);
void	set_wall_slice(t_wall_slice	*wall_slice, t_ray_cast *ray_cast);
void	draw_vertical_line(t_img *img, int x, t_wall_slice *wall_slice);

// 2D
void	draw_2d_wall(t_map *map, t_img *img_2d);
void	draw_2d_player(t_img *img_2d, t_player *player);

// draw line utils

// mlx utils
void my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
