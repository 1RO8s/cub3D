/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:33:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/07 11:47:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "conversion.h"

void	conversion(t_sm *machine)
{
	static t_f_conversion	f_conversion[10] = {
		decimal, decimal, unsign_decimal, octal, hexadecimal, hexadecimal,
		pointer, character, string, percent};
	int						i;
	int						bit_offset;

	i = 0;
	bit_offset = NB_FLAG + NB_FIELD + 1 + NB_PREFIX;
	while (i < NB_TYPE)
	{
		if ((machine->flag & (1 << i) << bit_offset))
			f_conversion[i](machine);
		i++;
	}
}
// NULL guard is required ??
//	if (machine == NULL)
//	{
//		machine->state = -1;
//		return ;
//	}
