/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:17:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/29 18:13:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "formalize.h"
#include "libft.h"
#include <stddef.h>

void	adjust_number(const char *str, t_sm *machine)
{
	if ((machine->prec == 0) && (machine->flag & BIT_PREC))
	{
		pad_width(machine, 0);
		pad_str(str, machine);
		return ;
	}
	if (ft_isxdigit(*str) == TRUE)
		sequence_unsigned(str, machine);
	else
		sequence_signed(str, machine);
}
