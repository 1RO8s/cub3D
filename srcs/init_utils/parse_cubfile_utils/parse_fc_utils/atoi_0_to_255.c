/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_0_to_255.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:48:39 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:34:23 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_rgb_info_missing(char *str, const char *entry,
		const char *rgb_str)
{
	if (*str == ',')
	{
		printf("%s%c: %s %s\n", ERR_PROMPT, *entry, EMSG_RGB_MISS, rgb_str);
		return (true);
	}
	return (false);
}

static bool	is_not_number(char *str, const char entry)
{
	if (*str != '\0' && *str != ',')
	{
		printf("%s%c: ", ERR_PROMPT, entry);
		printf("\"%c\" %s\n", *str, EMSG_RGB_NOT_NUM);
		return (false);
	}
	return (true);
}

static bool	is_range_number(bool is_range, char *start_str, const char entry)
{
	if (is_range == false)
	{
		printf("%s%c: ", ERR_PROMPT, entry);
		printf("\"%s\" %s\n", start_str, EMSG_RGB_RANGE_OUT);
		return (false);
	}
	return (true);
}

static int	calculate_from_string(char *str, const char *entry)
{
	int		result;
	bool	is_range;
	char	*start_str;

	is_range = true;
	start_str = str;
	result = 0;
	while (*str != '\0' && ft_isdigit(*str) == true)
	{
		while (result == 0 && *str == '0')
			str++;
		if (is_range == true)
			result = result * 10 + (*str - '0');
		if (result > 255)
			is_range = false;
		str++;
	}
	if (is_not_number(str, *entry) == false)
		return (-1);
	if (is_range_number(is_range, start_str, *entry) == false)
		return (-1);
	return (result);
}

/**
 * @brief convert string to intager value
 *
 * @param str is "0"~"255"
 * @param entry	is "F " or "C "
 *
 * @return OK(0~255), Error: -1
 * @note error case:(str==NULL, empty string, over range, non-digit characters)
 *  Put error message of each case
 */
int	atoi_0_to_255(char *str, const char *entry, const char *rgb_str)
{
	if (str == NULL)
		return (-1);
	while (*str != '\0' && *str == ' ')
		str++;
	if (*str == '\0')
	{
		printf("%s%c: ", ERR_PROMPT, *entry);
		printf("%s\n", EMSG_RGB_EMPTY);
		return (-1);
	}
	if (str == NULL)
		return (-1);
	if (is_rgb_info_missing(str, entry, rgb_str) == true)
		return (-1);
	return (calculate_from_string(str, entry));
}
