/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:19:09 by hnagasak          #+#    #+#             */
/*   Updated: 2024/08/26 02:01:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "type_cub3d.h"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define MAP_SCALE 4


//void initialize_player(t_game *game, int x, int y, char direction);
void init_game(t_game *game);
void render(t_game *game);
void my_mlx_pixel_put(t_debug *debug, int x, int y, int color);

#endif
