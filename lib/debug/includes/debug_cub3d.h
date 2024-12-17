/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:42:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 19:19:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_CUB3D_H
# define DEBUG_CUB3D_H

# include "type_cub3d.h"

# define LOG_FILE "debug.log"
# define IS_DEBUG 0
# define DEBUG_COLOR "\n\x1B[100m\x1B[37m"
# define RESET_COLOR "\x1B[0m\n"

// initialize game
int		init_debug_info(t_game *game);
void	debug_element_type(int fd, const char *str, const char *msg);
void	debug_texture(char *file, t_texture texture,
			const char *msg);
void	debug_img_tex(int fd, t_img img, int i, const char *msg);
void	debug_tex_info(int fd, t_info tex_info);
void	debug_parse_fc(int fd, int color[2], const char *msg);
void	debug_parse_map_fail(int fd, int i);
void	debug_map_data(t_map map, const char *msg);
void	debug_player(int fd, t_player player, const char *msg);
void	debug_get_rgb_color(int fd,
			t_type_fc type, int rgb[3], const char *msg);
void	put_visited(int fd, bool **visited, t_map *map);

// render frame
void	debug_moved_player(t_game *game);
void	debug_frame(t_game *game, const char *msg);

// 3D ray casting
void	debug_ray_cast(t_frame *frame, const char *msg, int x);
void	debug_is_hit_wall(t_frame *frame);
void	debug_dda(t_frame *frame, int type, const char *msg);
void	debug_wall_slice(int fd,
			double perp_wall_dist, t_wall_slice wall_slice, const char *msg);
void	debug_texture_coordinate(int fd, double wall_x, t_frame *frame,
			const char *msg);
void	debug_texture_y_coordinate_overflow(t_frame *frame, int y);
void	debug_put_texture_image(t_frame *frame);
void	debug_is_hit_wall(t_frame *frame);

// hook functions
void	debug_keypress(int fd, t_enum_key keytype, int keycode);

// common
int		open_log(const char *file_name, int oflag);

// double_to_string.c
void	double_to_string(double value, char *str, size_t n);
# define PRECISION	5
# define SIZE_DOUBLE_TO_STR 32

#endif
