/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:19:09 by hnagasak          #+#    #+#             */
/*   Updated: 2024/08/31 22:40:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// -------------- include ---------------
// project specific header files
# include "type_cub3d.h"

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

// -------------- function prototype ---------------
// main
//void initialize_player(t_game *game, int x, int y, char direction);
void	init_game(t_game *game);
void	render(t_game *game);

// 3D
void	init_ray(t_ray *ray, t_player *player, int x);
void	perform_dda(t_ray *ray, t_map *map, t_player *player);
void	set_wall_slice(t_wall_slice	*wall_slice, t_ray *ray);
void	draw_vertical_line(t_img *img, int x, t_wall_slice *wall_slice);

// 2D
void	draw_2d_wall(t_map *map, t_img *img_2d);
void	draw_2d_player(t_img *img_2d, t_player *player);

// draw line utils

// mlx utils
void my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
