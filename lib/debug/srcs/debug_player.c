#include "cub3d.h"

//typedef struct s_player {
//	t_vector	view_point;
//	t_vector	ray_dir;
//	t_vector	camera_forcal_plane;
//	double		move_speed;
//	double		rotate_speed;
//}	t_player;

static void	put_player(int fd, t_player player)
{
	int		original_stdout_fd;
	double	x;
	double	y;

	original_stdout_fd = set_stdout_fd(fd);
	x = player.view_point.x;
	y = player.view_point.y;
	printf("\tview_point          x[%f] y[%f]\n", x, y);
	x = player.ray_dir.x;
	y = player.ray_dir.y;
	printf("\tray_dir             x[%f] y[%f]\n", x, y);
	x = player.camera_forcal_plane.x;
	y = player.camera_forcal_plane.y;
	printf("\tcamera_forcal_plane x[%f] y[%f]\n", x, y);
	printf("\tmove_speed[%f]\trotate_speed[%f]\n",
			player.move_speed, player.rotate_speed);
	if (dup2(original_stdout_fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	close(original_stdout_fd);
}

void	debug_player(int fd, t_player player, const char *msg)
{
	if (IS_DEBUG != true)
		return ;
	dprintf(fd, "\n>>> func debug_player() ... call by '%s' <<<\n", msg);
	put_player(fd, player);
	dprintf(fd, "\n\n");
}
