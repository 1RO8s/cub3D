/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:18:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/31 15:20:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	get_color(t_Point3D *points, char *token)
{
	char	*end;

	if (ft_strnequ(token, "0x", 2) == true)
		points->color = ft_strtol(token, &end, 16);
	else
		points->color = COLOR;
}

static void	get_value(t_Point3D *points, int i, int j, char *token)
{
	points->x = j;
	points->y = i;
	points->z = ft_atoi((const char *)token);
}

void	set_points(char *file, t_Point3D **points, int rows, int cols)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	*token;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (i < rows)
	{
		j = 0;
		token = ft_strtok(line, DELIMITERS);
		while (j < cols)
		{
			get_value(&points[i][j], i, j, token);
			token = ft_strtok(NULL, DELIMITERS);
			get_color(&points[i][j], token);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
