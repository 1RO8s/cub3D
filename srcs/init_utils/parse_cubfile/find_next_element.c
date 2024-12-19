/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:41:18 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 19:14:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Find next line
 *
 * @param line
 *
 * @return exist next line ( NULL : next line is empty )
 */
const char	*find_next_element(const char *line)
{
	while (line != NULL)
	{
		line = find_next_line(line);
		if (line == NULL)
			return (NULL);
		if (*line != '\n')
			break ;
	}
	return (line);
}
