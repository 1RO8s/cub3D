/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:28:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 11:30:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"

void	adjust_hash(char *str, t_sm *machine)
{
	str[0] = '0';
	if ((machine->flag & (BIT_X | BIT_XMAJ)) != FALSE)
	{
		if ((machine->flag & BIT_X) != FALSE)
			str[1] = 'x';
		else
			str[1] = 'X';
	}
}
