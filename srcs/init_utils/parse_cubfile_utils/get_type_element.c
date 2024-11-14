/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:42:00 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 00:42:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_texture_element(const char *str)
{
	const char	*identifier[4];
	size_t		i;
	size_t		len;

	init_tex_keys(identifier, 4);
	i = 0;
	while (i < 4)
	{
		len = ft_strlen(identifier[i]);
		if (ft_strncmp(str, identifier[i], len) == 0)
			return (true);
		i++;
	}
	return (false);
}

static bool	is_floor_ceiling_element(const char *str)
{
	const char	*identifier[2] = {"F ", "C "};
	size_t		i;
	size_t		len;

	i = 0;
	while (i < 2)
	{
		len = ft_strlen(identifier[i]);
		if (ft_strncmp(str, identifier[i], len) == 0)
			return (true);
		i++;
	}
	return (false);
}

static bool	is_map_element(const char *str)
{
	const char	*identifier = " 10";
	size_t		i;
	size_t		len;

	if (*str == '\n')
		return (false);
	len = ft_strlen(identifier);
	while (*str != '\n')
	{
		i = 0;
		while (i < len)
		{
			if (ft_strncmp(str, identifier + i, (size_t)1) == 0)
				break ;
			i++;
		}
		if (i == len)
			return (false);
		str++;
	}
	return (true);
}

t_enum_elem	get_type_element(const char *line)
{
	if (is_texture_element(line) == true)
		return (ENUM_TEX);
	if (is_floor_ceiling_element(line) == true)
		return (ENUM_FC);
	if (is_map_element(line) == true)
		return (ENUM_MAP);
	return (ENUM_ELEMENT_ERR);
}
