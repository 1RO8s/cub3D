/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:04:40 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/29 22:51:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "formalize.h"
#include "libft.h"
#include <stddef.h>

static void	seq_s_right(const char *str, t_sm *machine)
{
	int	len;
	int	offset;

	len = (int)ft_strlen(str);
	offset = machine->prec + 1;
	if (len > machine->prec)
		offset = len;
	pad_width(machine, offset);
	if (machine->state == ERROR)
		return ;
	add_to_buff(str[0], machine);
	if (machine->state == ERROR)
		return ;
	pad_prec(machine, len);
	if (machine->state == ERROR)
		return ;
	pad_n_str(&str[1], machine, len - 1);
}

static void	seq_s_left(const char *str, t_sm *machine)
{
	int	len;
	int	offset;

	len = (int)ft_strlen(str);
	offset = machine->prec + 1;
	if (len > machine->prec)
		offset = len;
	add_to_buff(str[0], machine);
	if (machine->state == ERROR)
		return ;
	pad_prec(machine, len);
	if (machine->state == ERROR)
		return ;
	pad_n_str(&str[1], machine, len - 1);
	if (machine->state == ERROR)
		return ;
	pad_width(machine, offset);
}

void	sequence_signed(const char *str, t_sm *machine)
{
	if ((machine->flag & BIT_LEFT) != FALSE)
		seq_s_left(str, machine);
	else
		seq_s_right(str, machine);
}
//this code is error handle
//	if (machine->state == ERROR)
//		return ;
