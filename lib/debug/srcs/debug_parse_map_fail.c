/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse_map_fail.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:17:43 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/17 19:17:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_parse_map_fail(int fd, int i)
{
	if (IS_DEBUG != true)
		return ;
	ft_dprintf(fd, "fail : parse_map func[%d]\n", i);
}
