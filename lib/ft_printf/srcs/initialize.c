/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:50:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/07 11:51:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	initialize_machine(t_sm *machine, void *ap)
{
	machine->state = LETTER;
	machine->ap = ap;
	ft_bzero((void *)&machine->buffer, (size_t)4096);
	machine->out = ft_strnew(1);
	if (machine->out == NULL)
	{
		machine->state = ERROR;
		return ;
	}
	ft_bzero((void *)machine->out, 1);
	machine->out_size = 0;
	machine->len = 0;
	machine->flag = 0x0;
	machine->width = 0;
	machine->prec = 0;
}
