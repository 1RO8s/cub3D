/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:42:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/13 21:21:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_CUB3D_H
# define DEBUG_CUB3D_H

# include "type_cub3d.h"

# define LOG_FILE "debug.log"
# define IS_DEBUG 1

int	init_debug_info(t_game *game);

// 2D map
void	debug_map_data(t_map map);

// 3D ray casting
void	debug_ray_cast(t_ray_cast ray_cast, const char *msg, int x);

// common
int		open_log(const char *file_name, int oflag);

#endif
