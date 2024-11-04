/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:37:36 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/04 22:54:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**convert_str2array(const char *str_map)
{
	int		num_lines;
	int		max_length;
	int		length;
	char	**array;
	char	**lines;
	int		current_line;
	int		i;

	// 変数の初期化
	num_lines = 0;
	max_length = 0;
	// int numLines;
	lines = ft_split(str_map, '\n');
	// 行数と最大行長を計算
	num_lines = 0;
	while (lines[num_lines] != NULL)
	{
		length = ft_strlen(lines[num_lines]);
		// printf("max:%d len:%d\n",max_length, length);
		if (length > max_length)
			max_length = length;
		num_lines++;
	}
	// 配列のメモリを確保
	array = (char **)malloc((num_lines + 1) * sizeof(char *));
	i = 0;
	while (i < num_lines)
	{
		array[i] = (char *)malloc((max_length + 1) * sizeof(char));
		i++;
	}
	// 配列に行をコピー
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
	return (EXIT_SUCCESS);
}
