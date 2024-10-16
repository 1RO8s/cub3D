/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:19:09 by hnagasak          #+#    #+#             */
/*   Updated: 2024/10/15 15:47:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// -------------- include ---------------
// project specific header files
# include "type_cub3d.h"
# include <mlx.h>

// own libraries
# include "libft.h"
# include "ft_printf.h"
# include "debug_cub3d.h"

// stadard libraries
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

// -------------- define ---------------
// Cub3d game window
# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define MAP_SCALE 4
# define IMG_3D_WIDTH 512 
# define IMG_3D_HEIGHT WIN_HEIGHT
# define IMG_2D_WIDTH 512
# define IMG_2D_HEIGHT WIN_HEIGHT

// Cub3d color
# define COLOR_GREY 0xAAAAAA
# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000

// key code
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC	65307

// -------------  perform_dda ----------------
// ray_cast->grid_line
# define START_POINT -1
# define ON_VERTICAL_LINE 0
# define ON_HORIZONTAL_LINE 1

// -------------- function prototype ---------------
// main
int		init_game(t_game *game, int argc, char *argv[]);
void	render_frame(t_game *game);
int	handle_key_press(int keycode, t_game *game);
int		handle_mouse(int button, int x, int y, t_game *game);

// init_utils
int		init_mlx_window(t_game *game);
int		init_mlx_image(t_game *game);
int		init_cub_contents(t_game *game, char *filename);

// arg_check.c
int		arg_check(int argc, char *argv[]);
char	*read_cubfile(char *filepath);
char	*find_element_line(char *map, char *identifier);
char	*get_element_line(char *map, char *identifier);
char	*extract_value(char *line, char *identifier);
int		convert2color(char *rgb);
char	**convert_str2array(char *str_map);
void	free_double_pointer(char **array);

// parse_cubefile_utils
int		init_texture(void *mlx, t_texture *texture, char *file_contents);
char	*get_value_from_file_contents(char *file_contents, const char *key);
int		init_floor_and_ceiling(t_game *game, char *file_contents);
int		init_map(t_map *map, char *file_contents);
int		init_player(t_map *map, t_player *player);
int		set_direction(char direction, t_player *player);

// init_map.c
bool	is_enable_map(char *map_content);

// process drawing 3D image
void	init_ray(t_frame *frame, int x);
void	perform_dda(t_frame *frame, int x);
void	set_wall_slice(t_frame *frame, int x);
void	set_texture_x_coordinate(t_frame *frame, int x);
void	draw_vertical_line(t_frame *frame, int x);
typedef void	(*t_draw_3d_process)(t_frame *, int);

// wall slice utils
t_type_wall	get_texture_direction(int type_of_grid_line, t_vector ray_dir);

// 2D
void	draw_2d_wall(t_map *map, t_img *img_2d);
void	draw_2d_player(t_img *img_2d, t_player *player);

// draw line utils
void	draw_line(t_img *img, t_line *line);
void	init_plot(t_plot *plot, t_line *line);
void	init_color(t_clr *color, int start_color, int end_color);

// mlx utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// free utils
void	destroy_texture_image(void *mlx, t_texture *texture, int n);

// keypress utils
void	quit_game(int keycode, t_game *game);
void	set_move_forward_flag(int keycode, t_game *game);
void	set_move_backward_flag(int keycode, t_game *game);
void	set_strafe_left_flag(int keycode, t_game *game);
void	set_strafe_right_flag(int keycode, t_game *game);
void	set_rotate_left_flag(int keycode, t_game *game);
void	set_rotate_right_flag(int keycode, t_game *game);
void	invalid_key(int keycode, t_game *game);

typedef void	(*t_handle_key_press)(int, t_game *);

// update utils
# define MOVE_SPEED			0.2
# define ROTATE_SPEED		0.1
# define BIT_MOVE_FORWARD	0x01	// 0000 0001
# define BIT_MOVE_BACKWARD	0x02	// 0000 0010
# define BIT_STRAFE_LEFT	0x04	// 0000 0100
# define BIT_STRAFE_RIGHT	0x10	// 0000 1000
# define BIT_ROTATE_LEFT	0x20	// 0001 0000
# define BIT_ROTATE_RIGHT	0x40	// 0010 0000
void	move_forward(t_map *map, t_player *player);
typedef void	(*t_moving_player)(t_map *, t_player *);
bool	is_hit_flag(int flag, int bit);

#endif
