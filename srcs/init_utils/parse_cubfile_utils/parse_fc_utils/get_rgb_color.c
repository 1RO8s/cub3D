/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:17:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:19:11 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_rgb_miss(int i_rgb, char char_key, const char *rgb_str)
{
	if (i_rgb < 3)
	{
		printf("%s%c: %s %s\n",
			ERR_PROMPT, char_key, EMSG_RGB_MISS, rgb_str);
		return (false);
	}
	return (true);
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
		rgb[i] = atoi_0_to_255(str, key, rgb_str[i]);
		if (rgb[i] == -1)
			return (-1);
		i++;
		str = ft_strchr(str, ',');
		if (str == NULL)
			break ;
		str++;
	}
	if (is_rgb_miss(i, *key, rgb_str[i]) != true)
		return (-1);
	debug_get_rgb_color(debug_fd, type, rgb, "get_rgb_color()");
	color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (color);
}
