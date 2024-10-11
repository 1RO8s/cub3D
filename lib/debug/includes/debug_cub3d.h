/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:42:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 03:19:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_CUB3D_H
# define DEBUG_CUB3D_H

# include "type_cub3d.h"

# define LOG_FILE "debug.log"
# define IS_DEBUG 1
# define DEBUG_COLOR "\n\x1B[100m\x1B[37m"
# define RESET_COLOR "\x1B[0m\n"

// initialize game
int		init_debug_info(t_game *game);
void	debug_texture(char *xpm_file_name, t_texture texture,
			int i, const char *msg);
void	debug_img_tex(int fd, t_img img, int i, const char *msg);

// render frame
void	debug_frame(t_game *game, const char *msg);

// 2D map
void	debug_map_data(t_map map, const char *msg);

// 3D ray casting
void	debug_ray_cast(t_frame *frame, const char *msg, int x);
void	debug_is_hit_wall(t_frame *frame);
void	debug_dda(t_frame *frame, int type, const char *msg);
void	debug_wall_slice(int fd,
			double perp_wall_dist, t_wall_slice wall_slice, const char *msg);
void	debug_texture_coodinate(int fd, double wall_x, t_frame *frame);
void	debug_is_hit_wall(t_frame *frame);

// common
int		open_log(const char *file_name, int oflag);

#endif
