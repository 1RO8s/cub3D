/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:22:09 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/14 02:17:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//typedef struct s_player {
//	t_vector	view_point;
//	t_vector	ray_dir;
//	t_vector	camera_forcal_plane;
//	double		move_speed;
//	double		rotate_speed;
//}	t_player;

static void	put_view_point(int fd, double x, double y)
{
	char	str[SIZE_DOUBLE_TO_STR];

	double_to_string(x, str, sizeof(str));
	ft_dprintf(fd, "\tview_point          x[%s]", str);
	double_to_string(y, str, sizeof(str));
	ft_dprintf(fd, " y[%s]\n", str);
}

static void	put_ray_dir(int fd, double x, double y)
{
	char	str[SIZE_DOUBLE_TO_STR];

	double_to_string(x, str, sizeof(str));
	ft_dprintf(fd, "\tray_dir             x[%s]", str);
	double_to_string(y, str, sizeof(str));
	ft_dprintf(fd, "y[%s]\n", str);
}

static void	put_camera_forcal_plane(int fd, double x, double y)
{
	char	str[SIZE_DOUBLE_TO_STR];

	double_to_string(x, str, sizeof(str));
	ft_dprintf(fd, "\tcamera_forcal_plane x[%s]", str);
	double_to_string(y, str, sizeof(str));
	ft_dprintf(fd, " y[%s]\n", str);
}

static void	put_player_speed(int fd,
		double move_speed, double rotate_speed)
{
	char	str[SIZE_DOUBLE_TO_STR];

	double_to_string(move_speed, str, sizeof(str));
	ft_dprintf(fd, "\tmove_speed[%s]", str);
	double_to_string(rotate_speed, str, sizeof(str));
	ft_dprintf(fd, "\trotate_speed[%s]\n", str);
}

void	debug_player(int fd, t_player player, const char *msg)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, "\n>>> func debug_player() ... call by '%s' <<<\n", msg);
	put_view_point(fd, player.view_point.x, player.view_point.y);
	put_ray_dir(fd, player.ray_dir.x, player.ray_dir.y);
	put_camera_forcal_plane(fd,
		player.camera_forcal_plane.x, player.camera_forcal_plane.y);
	put_player_speed(fd, player.move_speed, player.rotate_speed);
	ft_dprintf(fd, "\n\n");
}
