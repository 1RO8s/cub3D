/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 07:32:41 by hnagasak          #+#    #+#             */
/*   Updated: 2024/08/08 04:45:43 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EXIT_FAILURE 1

#define ERRMSG_ARG_COUNT "Error:One argument must be specified\n"
#define ERRMSG_FILE_EXT "Error:Specify a file path with .cub extension\n"

/**
 * @brief Free the memory and set the pointer to NULL.
 * @param[in] ptr The pointer to be freed.
 * @return NULL always.
 */
void	*ft_free(void *ptr)
{
	// printf("\t1.ft_free: %p\n", ptr);
	if (ptr != NULL)
		free(ptr);
	// printf("\t2.ft_free: %p\n", ptr);
	return (NULL);
}

void	free_double_pointer(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		array[i] = ft_free(array[i]);
		i++;
	}
	ft_free(array);
}

/**
 * @brief Check the number of arguments and the file extension.
 * @param[in] argc The number of arguments.
 * @param[in] argv The arguments.
 */
int	arg_check(int argc, char *argv[])
{
	int		len;
	char	*ext;
	char	*filename;

	if (argc != 2)
	{
		// 引き数が1つじゃない場合
		printf(ERRMSG_ARG_COUNT);
		return (1);
	}
	filename = argv[1];
	len = ft_strlen(filename);
	ext = &filename[len - 4];
	if (ft_strncmp(".cub", ext, 4))
	{
		printf(ERRMSG_FILE_EXT);
		return (1);
	}
	return (0);
}

char	*ft_strjoin_nullable(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	return (ft_strjoin(s1, s2));
}

char	*read_cubfile(char *filepath)
{
	int		fd;
	char	*line;
	char	*map;
	char	*old;

	old = NULL;
	map = NULL;
	// printf("--- read_cubfile ---\n");
	fd = open(filepath, O_RDONLY);
	if (fd == -1 && printf("Error: file open failed\n"))
		return (NULL);
	line = malloc(1);
	while (line != NULL)
	{
		// printf("#### line: %p\n", line);
		line = ft_free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (map != NULL)
		{
			// printf("1: %p\n", map);
			map = ft_free(map);
		}
		// printf("Line: %s\n", line);
		map = ft_strjoin_nullable(old, line);
		// printf("MAP %p:\n_/_/_/_/_/\n%s\n_/_/_/_/_/\n", map, map);
		// printf("2: %p\n", old);
		if (old != NULL)
		{
			// printf("2.1: %p\n", old);
			old = ft_free(old);
		}
		// printf("3:map %p\n", map);
		old = ft_strdup(map);
		// printf("4:old %p\n", old);
	}
	// printf("5:%p\n", old);
	old = ft_free(old);
	close(fd);
	return (map);
}

// 行末またはEOFまでの文字列をコピーする
char	*duplicate_line(char *start)
{
	char	*end;
	size_t	len;
	char	*line;

	end = ft_strchr(start, '\n');
	if (end == NULL)
		end = ft_strchr(start, '\0');
	len = end - start;
	line = ft_substr(start, 0, len);
	return (line);
}

char	*find_element_line(char *map, char *identifier)
{
	char	*target;
	char	*line;

	// printf("--- find_identifier ---\n");
	// identifierが存在するか確認
	target = ft_strdup(identifier);
	// 1行目が'NO ./textures/north_61.xpm'であることを確認
	line = ft_strnstr(map, identifier, ft_strlen(map));
	if (line == NULL)
	{ // identifierが見つからなかった場合
		// 2行目以降で'NO ./textures/north_61.xpm'を探す
		target = ft_free(target);
		target = ft_strjoin_nullable("\n", identifier);
		line = ft_strnstr(map, identifier, ft_strlen(map));
	}
	if (line == NULL)
	{
		target = ft_free(target);
		printf("Error: %s identifier not found\n", identifier);
		return (NULL);
	}
	target = ft_free(target);
	return (line);
}

/**
 * @brief
 * @param[in] map
 * @param[in] identifier
 * @return char* identifierが見つかった場合はその行のコピー、見つからなかった場合はNULL
 */
char	*get_element_line(char *map, char *identifier)
{
	char	*line;

	line = find_element_line(map, identifier);
	line = duplicate_line(line);
	return (line);
}

// char *convert2path(char *line)
char	*extract_value(char *line)
{
	char	*value;
	char	**str_elm;
	int		elm_len;

	// printf("--- convert2path ---\n");
	str_elm = ft_split(line, ' ');
	elm_len = 0;
	while (str_elm[elm_len] != NULL)
		elm_len++;
	if (elm_len != 2)
	{
		printf("Error: invalid identifier format\n");
		free_double_pointer(str_elm);
		return (NULL);
	}
	value = ft_strdup(str_elm[1]);
	line = ft_free(line);
	free_double_pointer(str_elm);
	return (value);
}

// int rgb2hex(char *rgb)
int	convert2color(char *rgb)
{
	int		color;
	int		red;
	int		green;
	int		blue;
	char	**str_elm;

	str_elm = ft_split(rgb, ',');
	red = ft_atoi(str_elm[0]);
	green = ft_atoi(str_elm[1]);
	blue = ft_atoi(str_elm[2]);
	free_double_pointer(str_elm);
	color = (red << 16) + (green << 8) + blue;
	return (color);
}

/**
 * @brief Check if the wall textures are set.
 * @param[in] g t_game to set the elements
 * @param[in] g->cubfile The map to be verified
 * @return 1 if the wall textures are set, 0 otherwise
 */
int	has_elements(t_game *g)
{
	char	*floor_val;
	char	*ceil_val;

	// printf("--- has_wall_textures ---\n");
	g->north = get_element_line(g->cubfile, "NO");
	g->south = get_element_line(g->cubfile, "SO");
	g->west = get_element_line(g->cubfile, "WE");
	g->east = get_element_line(g->cubfile, "EA");
	floor_val = get_element_line(g->cubfile, "F");
	ceil_val = get_element_line(g->cubfile, "C");
	g->north = extract_value(g->north);
	g->south = extract_value(g->south);
	g->west = extract_value(g->west);
	g->east = extract_value(g->east);
	floor_val = extract_value(floor_val);
	ceil_val = extract_value(ceil_val);
	g->floor = convert2color(floor_val);
	g->ceiling = convert2color(ceil_val);
	floor_val = ft_free(floor_val);
	ceil_val = ft_free(ceil_val);
	return (true);
}

// void convertStringTo2DArray(char *input, char ***array, int *numLines, int *maxLength) {
char **convert_str2array(char *str_map) {
    // 変数の初期化
    int numLines = 0;
    int maxLength = 0;
		// int numLines;
		int length;
		char **array;

		char **lines;

		lines = ft_split(str_map, '\n');
		// 行数と最大行長を計算
		numLines = 0;
		while (lines[numLines] != NULL)
		{
			length = ft_strlen(lines[numLines]);
			if (length > maxLength)
				maxLength = length;
			numLines++;
		}

    // 配列のメモリを確保
    array = (char **)malloc(numLines * sizeof(char *));
    for (int i = 0; i < numLines; i++) {
        array[i] = (char *)malloc((maxLength + 1) * sizeof(char));
    }

    // 配列に行をコピー
    int currentLine = 0;
		while (lines[currentLine] != NULL)
		{
			ft_memchr(array[currentLine], ' ', maxLength);
			ft_strlcpy(array[currentLine], lines[currentLine], maxLength);
			array[currentLine][maxLength] = '\0';
			currentLine++;
		}
		free_double_pointer(lines);
		return (array);
}

int	extract_map(t_game *g)
{
	char	*north_ln;
	char	*south_ln;
	char	*west_ln;
	char	*east_ln;
	char	*floor_ln;
	char	*ceiling_ln;
	char	*map_ln_1st;
	char *str_map;

	// printf("--- extract_map ---\n");
	north_ln = find_element_line(g->cubfile, "NO");
	south_ln = find_element_line(g->cubfile, "SO");
	west_ln = find_element_line(g->cubfile, "WE");
	east_ln = find_element_line(g->cubfile, "EA");
	floor_ln = find_element_line(g->cubfile, "F");
	ceiling_ln = find_element_line(g->cubfile, "C");
	// TODO: 行頭が11のmap以外も探せるようにする
	map_ln_1st = find_element_line(g->cubfile, "11");
	// map_ln_1stが他の要素よりも前にある場合
	if (map_ln_1st < north_ln || map_ln_1st < south_ln || map_ln_1st < west_ln
		|| map_ln_1st < east_ln || map_ln_1st < floor_ln
		|| map_ln_1st < ceiling_ln)
	{
		printf("Error: map is not at the end of the file\n");
		// printf("map_ln_1st: %s\n", map_ln_1st);
		return (false);
	}

	str_map = ft_strdup(map_ln_1st);
	// printf("extract_map:\n%s\n----------\n", str_map);
	g->map = convert_str2array(str_map);
	ft_free(str_map);
	return (true);
}

/**
 * Returns 1 if it is a invalid map
 * @param[in]  g  t_game with map to be verified
 */
int	is_invalid_map(t_game *g)
{
	// 壁のテクスチャと床天井の色が設定されているか確認
	if (!has_elements(g))
		return (true);
	extract_map(g);
	return (false);
}
