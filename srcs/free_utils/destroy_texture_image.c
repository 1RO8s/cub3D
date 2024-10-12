/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_texture_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:01:38 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/11 10:05:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_texture_image(void *mlx, t_texture *texture, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		mlx_destroy_image(mlx, texture[i].img_tex.img);
		i++;
	}
}
