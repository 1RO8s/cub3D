/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:17:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 22:18:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char	*find_next_word(const char *s)
{
	if (s == NULL || *s == '\0' || *s == '\n')
		return (NULL);
	while (*s != ' ')
	{
		s++;
		if (*s == '\0' || *s == '\n')
			return (NULL);
	}
	while (*s == ' ')
	{
		s++;
		if (*s == '\0' || *s == '\n')
			return (NULL);
	}
	return (s);
}
