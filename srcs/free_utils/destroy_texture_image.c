/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_texture_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:01:38 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/16 07:43:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_texture_image(void *mlx, t_texture *texture, int flag)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 4)
	{
		bit = 0x01 < i;
		if (flag & bit)
			mlx_destroy_image(mlx, texture[i].img_tex.img);
		i++;
	}
}
// reference cub3d.h
//# define BIT_NORTH	0x01	// 0000 0000 0001
//# define BIT_WEST		0x02	// 0000 0000 0010
//# define BIT_EAST		0x04	// 0000 0000 0100
//# define BIT_SOUTH	0x08	// 0000 0000 1000
