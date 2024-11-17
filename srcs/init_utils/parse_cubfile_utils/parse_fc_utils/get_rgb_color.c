/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:17:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/18 03:00:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief 
 *
 * @param str
 * @param error
 *
 * @return OK(0~255), Error: -1
 * @note error case:(str==NULL, empty string, over range, non-digit characters)
 *  Put error message of each case
 */
static int	atoi_0_to_255(char *str, const char *entry)
{
	int		result;
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

void	debug_get_rgb_color(int fd, t_enum_fc type, int rgb[3], const char *msg)
{
	const char	*s[3] = {"r", "g", "b"};
	int			i;

	if (IS_DEBUG != true)
		return ;
	if (type == ENUM_F)
		ft_dprintf(fd, ">>> func debug_get_rgb_color <<< ... call by %s\n", msg);
	ft_dprintf(fd, "\tcolor[%d]", type);
	i = 0;
	while (i < 3)
	{
		ft_dprintf(fd, "\t%s[%d]", s[i], rgb[i]);
		i++;
	}
	ft_dprintf(fd, "\n");
	if (type == ENUM_C)
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
int	get_rgb_color(t_enum_fc type, const char *key, char *str, int debug_fd)
{
	int			color;
	int			rgb[3];
	const char	*rgb_str[3] = {"R", "G", "B"};
	int			i;

	color = 0;
	i = 0;
	while (str != NULL && *str != '\0' && i < 3)
	{
		if (*str == ',')
		{
			ft_dprintf(STDERR_FILENO, "%s%c: %s %s\n",
				ERR_PROMPT, *key, EMSG_RGB_MISS, rgb_str[i]);
			return (-1);
		}
		rgb[i] = atoi_0_to_255(str, key);
		if (rgb[i] == -1)
			return (-1);
		i++;
		str = ft_strchr(str, ',');
		if (str == NULL)
			break ;
		str++;
	}
	if (i < 3)
	{
		ft_dprintf(STDERR_FILENO, "%s%c: %s %s\n",
			ERR_PROMPT, *key, EMSG_RGB_MISS, rgb_str[i]);
		return (-1);
	}
	debug_get_rgb_color(debug_fd, type, rgb, "get_rgb_color()");
	color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (color);
}
