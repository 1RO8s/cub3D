/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:51:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/29 22:49:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "libft.h"

void	pad_str(const char *str, t_sm *machine)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(str);
	while (i < len && (machine->state != ERROR))
	{
		add_to_buff(str[i], machine);
		i++;
	}
}
