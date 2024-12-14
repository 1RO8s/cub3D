/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:17:19 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/14 23:52:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_not_number(char *str, const char entry)
{
	return (*str != '\0' && *str != ',');
}

/**
 * @brief convert a nurmeric string to intager value from RGB component 
 * (EX : "0,255,42", "255,42", "42")
 *
 * @param str is containing RGB values
 *
 * @return OK(0~255), Error: -1 ~ -4
 */
static t_resut	atoi_0_to_255(char *str)
{
	int		result;

	result = 0;
	if (*str == ',')
		return ((t_result){.value = -1, .err_msg = NULL);
	while (*str != '\0' && ft_isdigit(*str) == true)
	{
		while (result == 0 && *str == '0')
			str++;
		result = result * 10 + (*str - '0');
		if (result > 255)
			return ((t_result){.value = -2, .err_msg = NULL)};
		str++;
	}
	if (is_not_number(str) == true)
		return ((t_result){.value = -3, .err_msg = str);
	return ((t_result){.value = result, .err_msg = NULL});
}

/**
 * @brief get RGB color value from F or C line
 *
 * @param str : F or C line
 *
 * @return 0x00~0xFFFFFF (Success),  -1 or -2 or -3 or -4 (Failure)
 */
t_result	get_rgb_color(char *str)
{
	t_result			result[3];
	//int					rgb[3];
	static const char	*rgb_str[3] = {"R", "G", "B"};// static ??
	t_type_rgb			type;

	i = 0;
	while (str != NULL && *str != '\0' && type <= ENUM_B)
	{
		result = atoi_0_to_255(str);
		if (result.value == -1)
			return ((t_result){.value = -1, .err_msg = rgb_str[type]});
		if (result.value == -2)
			return ((t_result){.value = -2, .err_msg = str});
		if (result.value == -3)
			return ((t_result)result);
		type++;
		str = ft_strchr(str, ',');
		if (str == NULL)
			break ;
		str++;
		while (*str != '\0' && *str == ' ')
			str++;
	}
	if (type <= ENUM_B)
		return ((t_result){.value = -1, .err_msg = rgb_str[type]});
	if (str != NULL)
		return ((t_result){.value = -4, .err_msg = --str});
	debug_get_rgb_color(debug_fd, type, rgb, "get_rgb_color()");
	return ((t_result){(result.value[0] << 16) + (result.value[1] << 8) + result.value[2], NULL});
}
