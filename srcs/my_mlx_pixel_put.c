/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 02:00:13 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/26 02:03:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function to put a pixel in the image
void my_mlx_pixel_put(t_debug *debug, int x, int y, int color)
{
    char *dst;

    dst = debug->addr + (y * debug->line_length + x * (debug->bpp / 8));
    *(unsigned int*)dst = color;
}
