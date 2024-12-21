/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:44:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:31:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "process.h"
#include "conversion.h"
#include "va_arg.h"
#include "formalize.h"
#include "libft.h"

void	unsign_decimal(t_sm *machine)
{
	char				str[42];
	unsigned long long	num;
	int					base;

	ft_bzero(str, 42);
	base = 10;
	num = unsign_va_arg(machine);
	if (!((machine->flag & BIT_PREC) && (machine->prec == 0) && (num == 0)))
		itoa_buff(num, str, base, machine);
	formalize(str, machine);
}
