/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:30 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/30 00:10:40 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_data(t_map *map, const char *map_content)
{
	int	count;

	map->data = convert_str2array((char *)map_content);
	if (map->data == NULL)
		return (EXIT_FAILURE);
	map->width = ft_strlen(map->data[0]);
	count = 0;
	while (map->data[count] != NULL)
		count++;
	map->height = count;
	return (EXIT_SUCCESS);
}

//static char	*find_map_line(char *file_contents)
//{
//	// exist bug : 1th line of map "   111"
//	return (find_element_line(file_contents, "11"));
//}
//
//int	init_map(t_map *map, char *file_contents)
//{
//	char	*map_content;
//
//	map_content = find_map_line(file_contents);
//	if (map_content == NULL)
//	{
//		ft_dprintf(STDERR_FILENO, "Error: nonexist map\n");
//		return (EXIT_FAILURE);
//	}
//	if (is_enable_map(map_content) != true)
//	{
//		ft_dprintf(STDERR_FILENO, "Error: invalid map\n");
//		return (EXIT_FAILURE);
//	}
//	if (set_map_data(map, map_content) != EXIT_SUCCESS)
//		return (EXIT_FAILURE);
//	return (EXIT_SUCCESS);
//}

bool	is_last_map(const char *line)
{
	return (find_next_element(line) == NULL);
}

int	parse_map(const char *line, t_parse *parse)
{
	static t_is_valid_map	func[3] = {is_last_map, is_range_map, is_enclosed_map};
	int						i;

	i = 0;
	while (i < 3)
	{
		status = func[i](line, parse);
		if (status != EXIT_SUCCESS)
		{
			// print error:msg
			return (EXIT_FAILURE);
		}
		i++;
	}
	//printf("line[%s]\n", line);
	if (get_map_data(&parse->game->map, line) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (get_player_info(&parse->game->map, &parse->game->player) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
