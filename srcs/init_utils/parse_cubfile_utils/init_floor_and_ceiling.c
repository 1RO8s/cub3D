/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/27 11:24:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_floor_and_ceiling(t_game *game, char *file_contents)
{
	const char	*key[2] = {"F", "C"};
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
	if (color[0] == -1 || color[1] == -1)
		return (EXIT_FAILURE);
	game->floor_color = color[0];
	game->ceiling_color = color[1];
	game->frame.ceiling_color = &game->ceiling_color;
	game->frame.floor_color = &game->floor_color;
	return (EXIT_SUCCESS);
}

int	get_color(char *str)
{
	int	color;
	int	rgb[3];
	int	green;
	int	blue;
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == ',')
		{
			str++;
			continue;
		}
		rgb[i] = get_color_value(str);
		if (rgb[i] == -1)
			return (-1);
		i++;
		str++;
	}
	i = 0;
	printf("rgb");
	while (i < 3)
	{
		printf(" [%d]", rgb[i]);
		i++;
	}
	printf("\n");
	return (color);
}

int	parse_fc(const char *line, t_parse *parse)
{
	const char	*key[2] = {"F ", "C "};
	int			i;
	char		*color_str;
	int			color[2];

	while (line != NULL)
	{
		i = 0;
		while (i < 2)
		{
			if (is_key_line(line, key[i]) == false)
			{
				i++;
				continue ;
			}
			color_str = strdup_until_ch(&line[2], '\n');
			if (color_str == NULL)
				return (EXIT_FAILURE);
			color[i] = get_color(color_str);
			//color[i] = convert2color(color_str);
			free(color_str);
			break ;
		}
		if (i == 2)
		{
			ft_dprintf(STDERR, "%sfloor ceiling syntax\n", ERR_PROMPT);
			print_until_nl(STDERR, line);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (color[0] == -1 || color[1] == -1)
		return (EXIT_FAILURE);
	game->floor_color = color[0];
	game->ceiling_color = color[1];
	game->frame.ceiling_color = &game->ceiling_color;
	game->frame.floor_color = &game->floor_color;
	(void)parse;
	return (EXIT_SUCCESS);
}
