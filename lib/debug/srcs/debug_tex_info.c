/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tex_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:05:01 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 16:06:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_tex_info(int fd, t_tex_info tex_info)
{
	int		i;
	char	*bit_str;

	if (IS_DEBUG == false)
		return ;
	i = 0;
	while (i < 4)
	{
		bit_str = ft_itoa_binary(tex_info.bit[i]);
		if (bit_str == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error: ft_itoa_binary()\n");
			return ;
		}
		ft_dprintf(fd, "\tkey[%s]", tex_info.key[i]);
		ft_dprintf(fd, " bit[%s]\n", bit_str);
		free(bit_str);
		i++;
	}
}
