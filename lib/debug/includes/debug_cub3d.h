/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:42:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/31 22:40:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_CUB3D_H
# define DEBUG_CUB3D_H

# include "cub3d.h"
# include "ft_printf.h"

# define LOG_FILE "debug.log"

void	debug_map_data(t_map map);
int		open_log(const char *file_name, int oflag);

#endif
