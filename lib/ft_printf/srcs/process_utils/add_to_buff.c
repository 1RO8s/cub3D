/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:03:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/25 16:10:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	add_to_buff(const char c, t_sm *machine)
{
	if (machine->len == 4096)
	{
		machine->out = join_to_out(machine->out, machine->buffer, machine->len);
		if (machine->out == NULL)
		{
			machine->state = ERROR;
			return ;
		}
		ft_bzero(&machine->buffer, 4096);
		machine->len = 0;
	}
	machine->buffer[machine->len] = c;
	machine->len++;
	machine->out_size++;
}
//void idea
//		machine->out = ft_strjoin_free(machine->out, machine->buffer);
