/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:40:26 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:03:33 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_log(const char *file_name, int oflag)
{
	int	fd;

	if (oflag & O_TRUNC)
	{
		fd = open(file_name,
				O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	else if (oflag & O_APPEND)
	{
		fd = open(file_name,
				O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	else
		fd = -1;
	if (fd == -1)
		printf( "open");
	return (fd);
}
