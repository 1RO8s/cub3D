/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:37:36 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 20:02:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_map_size {
	size_t	rows;
	size_t	cols;
}	t_map_size;

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
		// printf("max:%d len:%d\n",max_length, length);
		if (tmp_len > cols)
			cols = tmp_len;
		rows++;
	}
	return ((t_map_size){.rows = rows, .cols = cols});
}

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

static char	**convert_str2array(const char *str_map)
{
	t_map_size	map_size;
	char	**array;
	char	**lines;
	int		current_line;
	//int		i;

	lines = ft_split(str_map, '\n');
	if (lines == NULL)
		return (NULL);
	map_size = get_map_size(lines);
	array = allocate_map(map_size);
	if (array == NULL)
		return (NULL);
	// 配列に行をコピー
	int	length;
	int	max_length = map_size.cols;
	current_line = 0;
	while (lines[current_line] != NULL)
	{
		length = ft_strlen(lines[current_line]);
		// printf("len:%d current line:%s\n",length, lines[current_line]);
		ft_memset(array[current_line], ' ', max_length);
		// printf("1.array:%s\n",array[current_line]);
		ft_memcpy(array[current_line], lines[current_line], length);
		// printf("2.array:%s\n",array[current_line]);
		array[current_line][max_length] = '\0';
		current_line++;
	}
	array[current_line] = NULL;
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
		return (EXIT_FAILURE);
	map->width = ft_strlen(map->data[0]);
	count = 0;
	while (map->data[count] != NULL)
		count++;
	map->height = count;
	debug_map_data(*map, "get_map_data()");
	parse->flag |= BIT_INIT_MAP;
	return (EXIT_SUCCESS);
}
