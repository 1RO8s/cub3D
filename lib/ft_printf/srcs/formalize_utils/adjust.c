/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:29:09 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/29 14:39:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "conversion.h"
#include "formalize.h"
#include "libft.h"

void	adjust(const char *str, t_sm *machine)
{
	if ((machine->flag & BIT_PREC) && (~machine->flag & BIT_C)
		&& (~machine->flag & BIT_PER))
		adjust_prec(str, machine);
	else
		adjust_width(str, machine);
}
//debug code
//#include <stdio.h>// for debug
//	printf("%d:width\n", machine->width);// for debug
//	printf("%d:precision\n", machine->prec);// for debug
//	printf("%d:len\n", len);// for debug
//	printf("%s:str\n", str);// for debug
//	char *flag_bin = (char *)ft_itoa_binary(machine->flag);// for debug
//	printf("%s:flag_bin\t%#x:flag\n", flag_bin, machine->flag);// for debug
//	free(flag_bin);// for debug
