/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enable_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:35 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/22 18:53:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_final_element(char *map_content)
{
	const char	*next_content;

	next_content = find_next_element(map_content);
	return (next_content == NULL);
}

bool	is_enable_map(char *map_content)
{
	if (is_final_element(map_content) == false)
		return (false);
//	if (is_closed_map() == false)
//		return (false);
//	if (is_other_invalid() == false)
//		return (false);
	return (true);
}
// Nessesary ?? ... because it checked with is_last_element()
//bool	is_enable_map(char *file_contents, char *map_content)
//{
//	char	*key[6] = {"NO", "SO", "WE", "EA", "F", "C"};
//	char	*other_content;
//	int		i;
//
//	 check the place where is map content in file_contents
//	i = 0;
//	while (i < 6)
//	{
//		other_content = find_element_line(file_contents, key[i]);
//		if (other_content == NULL)
//			return (false);
//		if (other_content > map_content)
//			return (false);
//		i++;
//	}
