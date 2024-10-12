/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/12 14:48:30 by kamitsui         ###   ########.fr       */
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

static char	*find_map_line(char *file_contents)
{
	// exist bug : 1th line of map "   111"
	return (find_element_line(file_contents, "11"));
}

int	init_map(t_map *map, char *file_contents)
{
	char	*map_content;

	map_content = find_map_line(file_contents);
	if (map_content == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error: nonexist map\n");
		return (EXIT_FAILURE);
	}
	if (is_enable_map(map_content) != true)
	{
		ft_dprintf(STDERR_FILENO, "Error: invalid map\n");
		return (EXIT_FAILURE);
	}
	if (set_map_data(map, map_content) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
