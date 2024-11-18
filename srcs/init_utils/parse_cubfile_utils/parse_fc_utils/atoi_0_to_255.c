/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_0_to_255.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:48:39 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/18 16:56:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	skip_blank_space(char *str, const char *entry)
{
	while (*str != '\0' && *str == ' ')
		str++;
	if (*str == '\0')
	{
		ft_dprintf(STDERR_FILENO, "%s%c: ",
			ERR_PROMPT, *entry);
		ft_dprintf(STDERR_FILENO, "%s\n", EMSG_RGB_EMPTY);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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
	int		result;
	char	*str_num;
	int		status;

	result = 0;
	status = 0;
	if (str == NULL)
		return (-1);
	if (skip_blank_space(str, entry) != EXIT_SUCCESS)
		return (-1);
	if (is_miss_rgb_
	if (*str == ',')
	{
		ft_dprintf(STDERR_FILENO, "%s%c: %s %s\n",
			ERR_PROMPT, *entry, EMSG_RGB_MISS, rgb_str);
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
	return (result);
}
