#include "cub3d.h"

//typedef struct s_player {
//	t_vector	view_point;
//	t_vector	ray_dir;
//	t_vector	camera_forcal_plane;
//	double		move_speed;
//	double		rotate_speed;
//}	t_player;

void	debug_player(int fd, t_player player, const char *msg)
{
	double	x;
	double	y;

	if (IS_DEBUG != true)
		return ;
	dprintf(fd, "\n>>> func debug_player() ... call by '%s' <<<\n", msg);
	x = player.view_point.x;
	y = player.view_point.y;
	dprintf(fd, "\tview_point          x[%f] y[%f]\n", x, y);
	x = player.ray_dir.x;
	y = player.ray_dir.y;
	dprintf(fd, "\tray_dir             x[%f] y[%f]\n", x, y);
	x = player.camera_forcal_plane.x;
	y = player.camera_forcal_plane.y;
	dprintf(fd, "\tcamera_forcal_plane x[%f] y[%f]\n", x, y);
	dprintf(fd, "\tmove_speed[%f]\trotate_speed[%f]\n",
			player.move_speed, player.rotate_speed);
	dprintf(fd, "\n\n");
}
