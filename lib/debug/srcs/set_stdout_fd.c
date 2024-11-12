/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdout_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:32:42 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 13:33:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(const char *cause)
{
	ft_dprintf(STDERR_FILENO, "%s\n", cause);
	exit(1);
}

int	set_stdout_fd(int fd)
{
	int	original_stdout_fd;

	original_stdout_fd = dup(STDOUT_FILENO);
	if (original_stdout_fd == -1)
		handle_error("dup");
	if (dup2(fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	return (original_stdout_fd);
}
