/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 01:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/12 15:41:25 by kamitsui         ###   ########.fr       */
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
int	atoi_0_to_255(char *str, const char *entry)
{
	int	result;
	char	*str_num;
	int		status;

	result = 0;
	status = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0' && *str == ' ')
		str++;
	if (*str == '\0')
	{
		ft_dprintf(STDERR_FILENO, "%s%c: ",
			ERR_PROMPT, *entry);
		ft_dprintf(STDERR_FILENO, "%s\n", EMSG_RGB_EMPTY);
		return (-1);
	}
	str_num = str;
	while (*str != '\0' && ft_isdigit(*str) == true)
	{
		while (result == 0 && *str == '0')
			str++;
		if (status != -1)
			result = result * 10 + (*str - '0');
		if (result > 255)
			status = -1;
		//if (result <= 255)
		//	status = 0;
		////printf("[%c] result[%d]", *str, result);
		//else
		//	status = -1;
		str++;
	}
	if (*str != '\0' && *str != ',')
	{
		ft_dprintf(STDERR_FILENO, "%s%c: ",
			ERR_PROMPT, *entry);
		ft_dprintf(STDERR_FILENO, "\"%c\" %s\n", *str, EMSG_RGB_NOT_NUM);
		return (-1);
	}
	if (status == -1)
	{
		ft_dprintf(STDERR_FILENO, "%s%c: ",
			ERR_PROMPT, *entry);
		*str = '\0';
		ft_dprintf(STDERR_FILENO, "\"%s\" %s\n", str_num, EMSG_RGB_RANGE_OUT);
		return (-1);
	}


//	while (*str != '\0' && *str == ' ')
//		str++;
//	if (*str != '\0')
//		return (-1);
	return (result);
}

void	debug_get_rgb_color(int first, int fd, int rgb[3], const char *msg)
{
	const char	*s[3] = {"r", "g", "b"};
	int			i;

	if (IS_DEBUG != true)
		return ;
	if (first == 0)
		ft_dprintf(fd, ">>> func debug_get_rgb_color <<< ... call by %s\n", msg);
	ft_dprintf(fd, "\tcolor[%d]", first);
	i = 0;
	while (i < 3)
	{
		ft_dprintf(fd, "\t%s[%d]", s[i], rgb[i]);
		i++;
	}
	ft_dprintf(fd, "\n");
	if (first == 1)
		ft_dprintf(fd, "\n");
}

/**
 * @brief 
 *
 * @param first
 * @param parse
 * @param str
 *
 * @return (0x00~0xFFFFFF) ... OK,  (-1) ... Fail
 */
int	get_rgb_color(int first, t_parse *parse, char *str)
{
	int	color;
	int	rgb[3];
	const char	*rgb_str[3] = {"R", "G", "B"};
	int	i;

	color = 0;
	i = 0;
	while (str != NULL && *str != '\0')
	{
		if (*str == ',')
		{
			ft_dprintf(STDERR_FILENO, "%s%c: %s %s\n", ERR_PROMPT, *parse->entry, EMSG_RGB_MISS, rgb_str[i]);
			return (-1);
		}
		rgb[i] = atoi_0_to_255(str, parse->entry);
		if (rgb[i] == -1)
		{
			//ft_dprintf(STDERR_FILENO, "%s%c: ",
			//	ERR_PROMPT, *parse->entry);
			return (-1);
		}
		i++;
		str = ft_strchr(str, ',');
		if (str == NULL)
			break ;
		str++;
	}
	if (i < 3)
	{
		ft_dprintf(STDERR_FILENO, "%s%c: %s %s\n", ERR_PROMPT, *parse->entry, EMSG_RGB_MISS, rgb_str[i]);
		return (-1);
	}
	debug_get_rgb_color(first, parse->game->debug.fd, rgb, "get_rgb_color()");
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
	int			bit[2] = {BIT_F, BIT_C};

	color[0] = -1;
	color[1] = -1;
	while (line != NULL && *line != '\n')
	{
		i = 0;
		while (i < 2)
		{
			if (is_key_line(line, key[i]) == false)
			{
				i++;
				continue ;
			}
			parse->entry = key[i];
			color_str = strdup_until_ch(&line[2], '\n');
			if (color_str == NULL)
				return (EXIT_FAILURE);
			// flag check & flag set
			if ((parse->flag & bit[i]) > 0)
			{
				ft_dprintf(STDERR_FILENO, "%s%c: %s\n",
					ERR_PROMPT, *key[i], EMSG_ENTRY_DUP);
				free(color_str);
				return (EXIT_FAILURE);
			}
			color[i] = get_rgb_color(i, parse, color_str);
			if (color[i] == -1)
				return (EXIT_FAILURE);
			parse->flag |= bit[i];
			free(color_str);
			break ;
		}
		if (i == 2)
		{
			put_error_msg(line, EMSG_ENTRY_INVAL);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	debug_parse_fc(parse->game->debug.fd, color, "parse_fc()");
	i = 0;
	while (i < 2)
	{
		if (color[i] == -1)
		{
			ft_dprintf(STDERR_FILENO, "%s%c: %s\n",
				ERR_PROMPT, *key[i], EMSG_ENTRY_MISS);
			return (EXIT_FAILURE);
		}
		i++;
	}
	parse->game->floor_color = color[0];
	parse->game->ceiling_color = color[1];
	parse->game->frame.ceiling_color = &parse->game->ceiling_color;
	parse->game->frame.floor_color = &parse->game->floor_color;
	return (EXIT_SUCCESS);
}
