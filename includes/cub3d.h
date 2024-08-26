/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:19:09 by hnagasak          #+#    #+#             */
/*   Updated: 2024/08/26 15:03:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "type_cub3d.h"

// Cub3d game window
# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define MAP_SCALE 4


// main
//void initialize_player(t_game *game, int x, int y, char direction);
void	init_game(t_game *game);
void	render(t_game *game);

// 3D

// 2D
void	draw_2d_wall(t_game *game);
void	draw_2d_player(t_game *game);

// draw line utils

// mlx utils
void my_mlx_pixel_put(t_debug *debug, int x, int y, int color);

#endif
