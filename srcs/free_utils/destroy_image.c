/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:01:38 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 02:15:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_n_image(void *mlx, t_img *img, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		mlx_destroy_image(mlx, img[i].img);
		i++;
	}
}