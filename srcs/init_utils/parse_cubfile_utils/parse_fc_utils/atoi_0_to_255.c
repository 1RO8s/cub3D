/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_0_to_255.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:48:39 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/14 21:13:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static bool	is_rgb_info_missing(
//		char *str, const char *entry, const char *rgb_str)
//{
//	if (*str == ',')
//	{
//		ft_dprintf(STDERR_FILENO, "%s%c: %s %s\n",
//			ERR_PROMPT, *entry, EMSG_RGB_MISS, rgb_str);
//		return (true);
//	}
//	return (false);
//}

static bool	is_not_number(char *str, const char entry)
{
	return (*str != '\0' && *str != ',');
//	if (*str != '\0' && *str != ',')
//	{
//		ft_dprintf(STDERR_FILENO, "%s%c: ",
//			ERR_PROMPT, entry);
//		ft_dprintf(STDERR_FILENO, "\"%c\" %s\n", *str, EMSG_RGB_NOT_NUM);
//		return (false);
//	}
//	return (true);
}

//static bool	is_range_number(bool is_range, char *start_str, const char entry)
//{
//	if (is_range == false)
//	{
//		ft_dprintf(STDERR_FILENO, "%s%c: ",
//			ERR_PROMPT, entry);
//		ft_dprintf(STDERR_FILENO, "\"%s\" %s\n", start_str, EMSG_RGB_RANGE_OUT);
//		return (false);
//	}
//	return (true);
//}

/**
 * @brief convert a nurmeric string to intager value from RGB component 
 * (EX : "0,255,42", "255,42", "42")
 *
 * @param str is containing RGB values
 *
 * @return OK(0~255), Error: -1 ~ -4
 */
t_resut	atoi_0_to_255(char *str)
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
