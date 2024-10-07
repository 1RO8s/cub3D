/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 15:29:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_map_data(t_map *map, char *map_content)
{
	int	count;

	map->data = convert_str2array(map_content);
	if (map->data == NULL)
		return (EXIT_FAILURE);
	map->width = ft_strlen(map->data[0]);
	count = 0;
	while (map->data[count] != NULL)
		count++;
	map->height = count;
	return (EXIT_SUCCESS);
}

char	*find_map_line(char *file_contents)
{
	return (find_element_line(file_contents, "11"));// exist bug : 1th line of map "   111"
}

int	init_map(t_map *map, char *file_contents)
{
	char	*map_content;

	map_content = find_map_line(file_contents);
	if (map_content == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error: nonexist map");
		return (EXIT_FAILURE);
	}
	if (is_enable_map(file_contents, map_content) != true)
	{
		ft_dprintf(STDERR_FILENO, "Error: invalid map");
		return (EXIT_FAILURE);
	}
	if (set_map_data(map, map_content) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//#define TEST_MAP_W_SIZE 10
//#define TEST_MAP_H_SIZE 20
//	const char	*test_data[] = {
//		"1111111111",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000000001",
//		"1000N00001",
//		"1000110001",
//		"1000000001",
//		"1000110001",
//		"1000000001",
//		"1000000001",
//		"1111111111",
//		NULL};

//#define TEST_MAP_W_SIZE 10
//#define TEST_MAP_H_SIZE 10
//	const char	*test_data[] = {
//		"1111111111",
//		"1111011111",
//		"1000000001",
//		"1000N00001",
//		"1000110001",
//		"1000000001",
//		"1000110001",
//		"1000000001",
//		"1000000001",
//		"1111111111",
//		NULL};
// ---- TEST_MAP ---- not use texture and selection F,C color
//int	read_map(t_map *map, char *file)
//{
//	(void)file;
//	map->width = TEST_MAP_W_SIZE;
//	map->height = TEST_MAP_H_SIZE;
//	map->data = (char **)malloc(sizeof(char *) * (map->height + 1));
//	if (map->data == NULL)
//		return (EXIT_FAILURE);
//	if (set_map_data(map->data, cubefile_contents) != EXIT_SUCCESS)
//	{
//		free(map->data);
//		return (EXIT_FAILURE);
//	}
//	return (EXIT_SUCCESS);;
//}
