/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_collision_detection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:20:01 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/17 11:20:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_collision_detection_x(
			char **data, t_vector view_point, double move_amount)
{
	int	x;
	int	y;

	x = (int)(view_point.x + move_amount);
	y = (int)(view_point.y);
	if (data[y][x] == '1')
		return (true);
	return (false);
}

bool	is_collision_detection_y(
			char **data, t_vector view_point, double move_amount)
{
	int	x;
	int	y;

	x = (int)(view_point.x);
	y = (int)(view_point.y + move_amount);
	if (data[y][x] == '1')
		return (true);
	return (false);
}
