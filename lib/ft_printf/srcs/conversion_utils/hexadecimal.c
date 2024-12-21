/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:41:26 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:32:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "conversion.h"
#include "va_arg.h"
#include "formalize.h"
#include "libft.h"

void	hexadecimal(t_sm *machine)
{
	char				str[42];
	unsigned long long	num;
	int					base;

	ft_bzero(str, 42);
	base = 0x10;
	num = unsign_va_arg(machine);
	if (!((machine->flag & BIT_PREC) && (machine->prec == 0) && (num == 0)))
	{
		if ((machine->flag & BIT_HASH) != FALSE)
		{
			adjust_hash(str, machine);
			itoa_buff(num, &str[2], base, machine);
		}
		else
			itoa_buff(num, str, base, machine);
	}
	formalize(str, machine);
}
//better idea
//	ft_bzero(str, 42);//42 is not better  >> xx_SIZE
