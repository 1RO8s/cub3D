/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/07 01:17:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_floor_and_ceiling(t_game *game, char *file_contents)
{
	const char	key[2] = {"F", "C"};
	int			i;
	char		*color_str;
	int			color[2];

	i = 0;
	while (i < 2)
	{
		color_str = get_value_from_file_contents(file_contents, key[i]);
		if (color_str == NULL)
			return (EXIT_FAILURE);
		color[i] = convert2color(color_str);
		free(color_str);
		i++;
	}
	if (color[0] == -1 || color[1] == -1)// nessesary ?
		return (EXIT_FAILURE);
	game->floor_color = color[0];
	game->ceiling_color = color[1];
	return (EXIT_SUCCESS);
}
