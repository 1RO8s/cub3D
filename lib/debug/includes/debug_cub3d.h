/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:42:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 10:54:11 by kamitsui         ###   ########.fr       */
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
int	init_debug_info(t_game *game);

// render frame
void	debug_frame(t_game *game, const char *msg);

// 2D map
void	debug_map_data(t_map map, const char *msg);

// 3D ray casting
void	debug_ray_cast(t_ray_cast ray_cast, const char *msg, int x);
void	debug_wall_slice(t_ray_cast *ray_cast, t_wall_slice *wall_slice,
			int line_height, const char *msg);
void	debug_dda(t_ray_cast *ray_cast, t_player *player, const char *msg);
void	debug_is_hit_wall(t_map *map, t_ray_cast *ray_cast);

// common
int		open_log(const char *file_name, int oflag);

#endif
