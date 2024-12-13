/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:37:36 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:19:12 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_size	get_map_size(char **lines)
{
	size_t	rows;
	size_t	cols;
	size_t	tmp_len;

	rows = 0;
	cols = 0;
	while (lines[rows] != NULL)
	{
		tmp_len = ft_strlen(lines[rows]);
		if (tmp_len > cols)
			cols = tmp_len;
		rows++;
	}
	return ((t_map_size){.rows = rows, .cols = cols});
}

// leak check for allocate_map()
//void	*malloc_(size_t n)
//{
//	(void)n;
//	return (NULL);
//}
// replace code
//		if (i == 3)
//			array[i] = (char *)malloc_((cols + 1) * sizeof(char));
//		else
//			array[i] = (char *)malloc((cols + 1) * sizeof(char));

char	**allocate_map(t_map_size map_size)
{
	size_t	i;
	size_t	rows;
	size_t	cols;
	char	**array;

	rows = map_size.rows;
	cols = map_size.cols;
	array = (char **)malloc((rows + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = (char *)malloc((cols + 1) * sizeof(char));
		if (array[i] == NULL)
		{
			free_double_pointer_n(array, i);
			return (NULL);
		}
		i++;
	}
	return (array);
}

static void	copy_and_pad_lines(char **src, char **dst, size_t max_len)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (src[i] != NULL)
	{
		len = ft_strlen(src[i]);
		ft_memset(dst[i], ' ', max_len);
		ft_memcpy(dst[i], src[i], len);
		dst[i][max_len] = '\0';
		i++;
	}
	dst[i] = NULL;
}

// leak check
//char **ft_split_(const char *s, int c)
//{
//	(void)s;
//	(void)c;
//	return (NULL);
//}

static char	**convert_str2array(const char *str_map)
{
	t_map_size	map_size;
	char		**array;
	char		**lines;

	lines = ft_split(str_map, '\n');
	if (lines == NULL)
		return (NULL);
	map_size = get_map_size(lines);
	array = allocate_map(map_size);
	if (array == NULL)
	{
		free_double_pointer(lines);
		return (NULL);
	}
	copy_and_pad_lines(lines, array, map_size.cols);
	free_double_pointer(lines);
	return (array);
}

int	get_map_data(const char *line, t_parse *parse)
{
	int		count;
	t_map	*map;

	map = &parse->game->map;
	map->data = convert_str2array(line);
	if (map->data == NULL)
	{
		printf("Error: convert_str2array() fail\n");
		return (EXIT_FAILURE);
	}
	map->width = ft_strlen(map->data[0]);
	count = 0;
	while (map->data[count] != NULL)
		count++;
	map->height = count;
	debug_map_data(*map, "get_map_data()");
	parse->flag |= BIT_INIT_MAP;
	return (EXIT_SUCCESS);
}
