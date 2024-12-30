/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/26 12:17:46 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "formalize.h"

void	adjust_prec(const char *str, t_sm *machine)
{
	if ((machine->flag & BIT_S) != FALSE)
		adjust_string(str, machine);
	else
		adjust_number(str, machine);
}
//this code moved ajust_number.c
//	if ((machine->prec == 0)
//		&& ((machine->flag & (BIT_D | BIT_I | BIT_U | BIT_X | BIT_XMAJ))
//			!= FALSE))
//	{
//		pad_width(machine, 0);
//		return ;
//	}
