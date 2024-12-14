/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_element_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:10:09 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/14 23:42:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_element_type(int fd, const char *str, const char *msg)
{
	t_type_elem	type;
	static int	count = 0;

	if (IS_DEBUG == false)
		return ;
	ft_dprintf(fd,
		"\n\n>>> func debug_element_type() ... call by '%s' <<<\n", msg);
	type = get_type_element(str);
	ft_dprintf(fd, "\tNo.%d first_char[%c]%p\n", count, *str, str);
	ft_dprintf(fd, "\telement type [%d] ... tex[%d] fc[%d] map[%d] err[%d]\n",
		(int)type, (int)ENUM_TEX, (int)ENUM_FC,
		(int)ENUM_MAP, (int)ENUM_ELEMENT_ERR);
	ft_dprintf(fd, "\t---- current element ----\n");
	ft_dprintf(fd, "%s\t-------------------------\n", str);
	count++;
}
