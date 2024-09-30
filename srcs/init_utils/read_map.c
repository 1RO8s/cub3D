/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/09/30 09:37:46 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define TEST_DATA \
	{ \
		"1111111111", \
		"1111011111", \
		"1000000001", \
		"1000N00001", \
		"1000110001", \
		"1000000001", \
		"1000110001", \
		"1000000001", \
		"1000000001", \
		"1111111111", \
		NULL \
	}
#define TEST_MAP_W_SIZE 10
#define TEST_MAP_H_SIZE 10

//#define TEST_DATA \
//	{ \
//		"1111111111", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000000001", \
//		"1000N00001", \
//		"1000110001", \
//		"1000000001", \
//		"1000110001", \
//		"1000000001", \
//		"1000000001", \
//		"1111111111", \
//		NULL \
//	}
//#define TEST_MAP_W_SIZE 10
//#define TEST_MAP_H_SIZE 20


static int	set_map_data(char **data)
{
	int			i;
	const char	*test_data[] = TEST_DATA;

	i = 0;
	while (test_data[i] != NULL)
	{
		data[i] = ft_strdup(test_data[i]);
		if (data[i] == NULL)
		{
			// free_data(data, i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	data[i] = NULL;
	return (EXIT_SUCCESS);
}

int	read_map(t_map *map, char *file)
{
	// ---- map/*.cub file ---- unfinished
	//char *cubefile_contents = read_cubfile(file);
	//if (cubefile_contents == NULL)
	//{
	//	ft_dprintf(STDERR_FILENO, "Error: file read failed\n");
	//	return (EXIT_FAILURE);
	//}
	//if(set_map_info(***) != true)
	//{
	//	ft_dprintf(STDERR_FILENO, "Error: invalid map\n");
	//	return (EXIT_FAILURE);
	//}
	// ---- TEST_MAP ---- not use texture and selection F,C color
	(void)file;
	map->width = TEST_MAP_W_SIZE;
	map->height = TEST_MAP_H_SIZE;
	map->data = (char **)malloc(sizeof(char *) * (TEST_MAP_H_SIZE + 1));
	if (map->data == NULL)
		return (EXIT_FAILURE);
	return (set_map_data(map->data));
}
