/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_wall_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:02:39 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 14:08:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_perp_wall_dist(int fd, double perp_wall_dist)
{
	int	original_stdout_fd;

	original_stdout_fd = set_stdout_fd(fd);
	printf("\tperp_wall_dist = [%f]\n", perp_wall_dist);
	if (dup2(original_stdout_fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	close(original_stdout_fd);
}

void	debug_wall_slice(int fd,
			double perp_wall_dist, t_wall_slice wall_slice, const char *msg)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, "\n\n>>> func debug_wall_slice() ... call by '%s' <<<\n", msg);
	put_perp_wall_dist(fd, perp_wall_dist);
	ft_dprintf(fd, "---- wall_slice ----\n");
	ft_dprintf(fd, "\tline_height = [%d]\n", wall_slice.line_height);
	ft_dprintf(fd, "\tstart       = [%d]\n", wall_slice.draw_start);
	ft_dprintf(fd, "\tend         = [%d]\n", wall_slice.draw_end);
	ft_dprintf(fd, "\tcolor       = [0x%X]\n", wall_slice.color);
	ft_dprintf(fd, "\n\n");
}
