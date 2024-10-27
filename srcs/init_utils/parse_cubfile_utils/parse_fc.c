/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/28 05:49:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// before
//int	init_floor_and_ceiling(t_game *game, char *file_contents)
//{
//	const char	*key[2] = {"F", "C"};
//	int			i;
//	char		*color_str;
//	int			color[2];
//
//	i = 0;
//	while (i < 2)
//	{
//		color_str = get_value_from_file_contents(file_contents, key[i]);
//		if (color_str == NULL)
//			return (EXIT_FAILURE);
//		color[i] = convert2color(color_str);
//		free(color_str);
//		i++;
//	}
//	if (color[0] == -1 || color[1] == -1)
//		return (EXIT_FAILURE);
//	game->floor_color = color[0];
//	game->ceiling_color = color[1];
//	game->frame.ceiling_color = &game->ceiling_color;
//	game->frame.floor_color = &game->floor_color;
//	return (EXIT_SUCCESS);
//}

/**
 * @brief 
 *
 * @param str
 * @param error
 *
 * @return OK(0~255), Error: -1(str==NULL, empty string, over range, non-digit characters)
 */
int	atoi_0_to_255(char *str)
{
	int	result;

	result = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0' && *str == ' ')
		str++;
	if (*str == '\0')
		return (-1);
	while (*str != '\0' && ft_isdigit(*str) == true)
	{
		result = result * 10 + (*str - '0');
		//printf("[%c] result[%d]", *str, result);
		if (result > 255)
		{
			//printf("error : result[%d]\n", result);
			return (-1);
		}
		str++;
	}
	//printf("result[%d]\n", result);

//	while (*str != '\0' && *str == ' ')
//		str++;
//	if (*str != '\0')
//		return (-1);
	return (result);
}

void	debug_get_rgb_color(int fd, int rgb[3], const char *msg)
{
	const char	*s[3] = {"r", "g", "b"};
	int			i;

	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, ">>> func debug_get_rgb_color <<< ... call by %s\n", msg);
	i = 0;
	while (i < 3)
	{
		ft_dprintf(fd, "\t%s[%d]", s[i], rgb[i]);
		i++;
	}
	ft_dprintf(fd, "\n\n");

}

int	get_rgb_color(char *str)
{
	int	color;
	int	rgb[3];
	int	i;

	color = 0;
	i = 0;
	while (str != NULL && *str != '\0')
	{
		if (*str == ',')
		{
			str++;
			continue;
		}
		rgb[i] = atoi_0_to_255(str);
		if (rgb[i] == -1)
			return (-1);
		i++;
		str = ft_strchr(str, ',');
	}
	debug_get_rgb_color(STDOUT_FILENO, rgb, "get_rgb_color()");
	color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (color);
}

void	debug_parse_fc(int fd, int	color[2], const char *msg)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, ">>> func debug_get_rgb_color <<< ... call by %s\n", msg);
	ft_dprintf(fd, "\tF color[%x]\n", color[0]);
	ft_dprintf(fd, "\tC color[%x]\n", color[1]);
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
			// flag check & flag set
			color[i] = get_rgb_color(color_str);
			//color[i] = convert2color(color_str);
			free(color_str);
			break ;
		}
		line = find_next_line(line);
	}
	debug_parse_fc(parse->game->debug.fd, color, "parse_fc()");
	if (color[0] == -1 || color[1] == -1)
	{
		// print error msg
		return (EXIT_FAILURE);
	}
	parse->game->floor_color = color[0];
	parse->game->ceiling_color = color[1];
	parse->game->frame.ceiling_color = &parse->game->ceiling_color;
	parse->game->frame.floor_color = &parse->game->floor_color;
	return (EXIT_SUCCESS);
}
