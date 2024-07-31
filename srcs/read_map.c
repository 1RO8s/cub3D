/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:40:33 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/26 13:18:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	count_width_depth(int fd, char *line, int *width, int *depth)
{
	int		pre_width;
	char	*line_trim;

	line_trim = ft_strtrim(line, " \n");
	*width = ft_count_words(line_trim, ' ');
	free(line_trim);
	pre_width = *width;
	*depth = *depth + 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_trim = ft_strtrim(line, " \n");
		*width = ft_count_words(line_trim, ' ');
		free(line_trim);
		if (pre_width != *width)
			error_fdf(ERR_MAP);
		if (ft_isprint(*line) == true)
			*depth = *depth + 1;
		free(line);
	}
}

static	void	get_rows_cols(char *file, int *rows, int *cols)
{
	int		fd;
	char	*line;
	int		width;
	int		depth;

	width = 0;
	depth = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_errno_exit(file);
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	count_width_depth(fd, line, &width, &depth);
	free(line);
	close(fd);
	*rows = depth;
	*cols = width;
	return ;
}

static t_Point3D	**allocate_points(int rows, int cols)
{
	t_Point3D	**points;
	int			i;

	points = (t_Point3D **)malloc(rows * sizeof(t_Point3D *));
	if (points == NULL)
		ft_errno_exit("malloc");
	i = 0;
	while (i < rows)
	{
		points[i] = (t_Point3D *)malloc(cols * sizeof(t_Point3D));
		if (points[i] == NULL)
			ft_errno_exit("malloc");
		i++;
	}
	return (points);
}

void	read_map(char *file, t_fdf *fdf)
{
	get_rows_cols(file, &fdf->map->rows, &fdf->map->cols);
	fdf->points = allocate_points(fdf->map->rows, fdf->map->cols);
	set_points(file, fdf->points, fdf->map->rows, fdf->map->cols);
}
