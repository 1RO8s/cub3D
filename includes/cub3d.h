/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:19:09 by hnagasak          #+#    #+#             */
/*   Updated: 2024/11/15 00:54:11 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// -------------- include ---------------
// project specific header files
# include "type_cub3d.h"
# include "error_cub3d.h"
# include <mlx.h>

// own libraries
# include "libft.h"
# include "get_next_line.h"
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
# define IMG_3D_WIDTH 1024
# define IMG_3D_HEIGHT WIN_HEIGHT
# define IMG_2D_WIDTH 512
# define IMG_2D_HEIGHT WIN_HEIGHT
# define DISABLE_2D_MAP 0

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
// srcs/
// call by main
int			init_game(t_game *game, int argc, char *argv[]);
int			end_game(t_game *game);
void		render_frame(t_game *game);
int			handle_key_press(int keycode, t_game *game);
int			handle_mouse(int button, int x, int y, t_game *game);

// srcs/
// │
// └ init_utils
int			init_mlx_window(t_game *game);
int			init_mlx_image(t_game *game);
int			init_cub_contents(t_game *game, char *filename);

// srcs/init_utils/
// │
// └ read_cubfile_utils
char		*ft_strjoin_nullable(char *s1, char *s2);

// srcs/init_utils/
// │
// └ parse_cubfile_utils

// call by init_cub_contents()
const char	*find_next_element(const char *line);
t_enum_elem	get_type_element(const char *line);
typedef int		(*t_parse_elem)(const char *, t_parse *);
int			parse_tex(const char *line, t_parse *parse);
int			parse_fc(const char *line, t_parse *parse);
int			parse_map(const char *line, t_parse *parse);

// parse_general_func.c
char		*find_next_line(const char *contents);
bool		is_key_line(const char *line, const char *key);
char		*strdup_until_ch(const char *line, int until_ch);
int			print_until_nl(int fd, const char *str);
void		init_tex_keys(const char *keys[], int size);

// put_error_msg.c
void		put_error_msg(const char *entry, const char *msg);

// call by parse_tex()
int	create_texture_images(const char *line, t_parse *parse);

// srcs/init_utils/parse_cubfile_utils/
// │
// └ parse_map_utils

// call by parse_map()
typedef int		(*t_parse_map)(const char *, t_parse *parse);
int			check_last_map(const char *line, t_parse *parse);
int			check_range_map(const char *line, t_parse *parse);
int			get_map_data(const char *line, t_parse *parse);
int			get_player_info(const char *line, t_parse *parse);
int			check_enclosed_by_walls(const char *line, t_parse *parse);

// call by get_player_info()
int			set_direction(char direction, t_player *player);

// parse->flag
# define BIT_NORTH		0x01	// 0000 0000 0001
# define BIT_WEST		0x02	// 0000 0000 0010
# define BIT_EAST		0x04	// 0000 0000 0100
# define BIT_SOUTH		0x08	// 0000 0000 1000
# define BIT_F			0x10	// 0000 0001 0000
# define BIT_C			0x20	// 0000 0010 0000
# define BIT_PLAYER		0x40	// 0000 0100 0000
# define BIT_MAP		0x80	// 0000 1000 0000
# define BIT_INIT_TEX	0x100	// 0001 0000 0000
# define BIT_INIT_MAP	0x200	// 0010 0000 0000

// srcs/
// │
// └ draw_3d_utils

// ray cast process for drawing 3D image
void		init_ray(t_frame *frame, int x);
void		perform_dda(t_frame *frame, int x);
void		set_wall_slice(t_frame *frame, int x);
void		set_texture_x_coordinate(t_frame *frame, int x);
void		draw_vertical_line(t_frame *frame, int x);
typedef void	(*t_draw_3d_process)(t_frame *, int);

// call by
// draw_vertical_line() & debug_texture_y_coordinate_overflow()
int			get_texture_y_coordinate(t_frame *frame, int y);

// call by debug_texture_coordinate()
t_type_wall	get_texture_direction(
				int type_of_grid_line, t_vector ray_dir);

// srcs/
// │
// └ draw_2d_utils
void		draw_2d_wall(t_map *map, t_img *img_2d);
void		draw_2d_player(t_img *img_2d, t_player *player);

// srcs/
// │
// └ draw_line_utils
void		draw_line(t_img *img, t_line *line);
void		init_plot(t_plot *plot, t_line *line);
void		init_color(t_clr *color, int start_color, int end_color);

// srcs/
// │
// └ free_utils
void		destroy_texture_image(void *mlx, t_texture *texture, int n);
void		*ft_free(void *ptr);
void		free_double_pointer(char **array);

// srcs/
// │
// └ mlx utils
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

// srcs/
// │
// └ keypress utils
// call by handle_key_press()
void		quit_game(int keycode, t_game *game);
void		set_move_forward_flag(int keycode, t_game *game);
void		set_move_backward_flag(int keycode, t_game *game);
void		set_strafe_left_flag(int keycode, t_game *game);
void		set_strafe_right_flag(int keycode, t_game *game);
void		set_rotate_left_flag(int keycode, t_game *game);
void		set_rotate_right_flag(int keycode, t_game *game);
void		invalid_key(int keycode, t_game *game);
typedef void	(*t_handle_key_press)(int, t_game *);

// update utils
// srcs/
// │
// └ update utils
# define MOVE_SPEED			0.1
# define ROTATE_SPEED		0.05
# define BIT_MOVE_FORWARD	0x01	// 0000 0001
# define BIT_MOVE_BACKWARD	0x02	// 0000 0010
# define BIT_STRAFE_LEFT	0x04	// 0000 0100
# define BIT_STRAFE_RIGHT	0x08	// 0000 1000
# define BIT_ROTATE_LEFT	0x10	// 0001 0000
# define BIT_ROTATE_RIGHT	0x20	// 0010 0000
void		move_forward(t_map *map, t_player *player);
void		move_backward(t_map *map, t_player *player);
void		strafe_left(t_map *map, t_player *player);
void		strafe_right(t_map *map, t_player *player);
void		rotate_left(t_map *map, t_player *player);
void		rotate_right(t_map *map, t_player *player);
typedef void	(*t_moving_player)(t_map *, t_player *);

bool		is_hit_flag(int flag, int bit);
bool		is_collision_detection_x(
				char **data, t_vector view_point, double move_amount);
bool		is_collision_detection_y(
				char **data, t_vector view_point, double move_amount);

#endif
