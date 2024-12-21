/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:03:38 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/29 22:52:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "formalize.h"
#include "libft.h"
#include <stddef.h>

static void	case_pad_zero_prec(const char *str, t_sm *machine, int len)
{
	int	literal;
	int	i;

	literal = 2;
	pad_n_str(str, machine, literal);
	i = 0;
	while ((i + len - literal < machine->prec) && (machine->state != ERROR))
	{
		add_to_buff('0', machine);
		i++;
	}
	pad_n_str(&str[literal], machine, len - literal);
}

static void	seq_u_right(const char *str, t_sm *machine)
{
	int	len;
	int	offset;
	int	literal;

	len = (int)ft_strlen(str);
	literal = 2 * (((machine->flag & BIT_HASH)
				&& (machine->flag & (BIT_X | BIT_XMAJ)))
			|| (machine->flag & BIT_P));
	offset = machine->prec + literal;
	if (len > machine->prec)
		offset = len;
	pad_width(machine, offset);
	if (machine->state == ERROR)
		return ;
	if (((machine->flag & BIT_P) != FALSE)
		|| (((machine->flag & (BIT_X | BIT_XMAJ))
				&& (machine->flag & BIT_HASH)) != FALSE))
		case_pad_zero_prec(str, machine, len);
	else
	{
		pad_prec(machine, len + 1);
		if (machine->state == ERROR)
			return ;
		pad_n_str(str, machine, len);
	}
}

static void	seq_u_left(const char *str, t_sm *machine)
{
	int	len;
	int	offset;

	len = (int)ft_strlen(str);
	offset = machine->prec;
	if (len > machine->prec)
		offset = len;
	pad_prec(machine, len + 1);
	if (machine->state == ERROR)
		return ;
	pad_n_str(str, machine, len);
	if (machine->state == ERROR)
		return ;
	pad_width(machine, offset);
}

void	sequence_unsigned(const char *str, t_sm *machine)
{
	if ((machine->flag & BIT_LEFT) != FALSE)
		seq_u_left(str, machine);
	else
		seq_u_right(str, machine);
}
//this code is error handle
//	if (machine->state == ERROR)
//		return ;
//void code from seq_u_right
//	if (machine->prec == 0)
//	{
////		if ((str[literal] == '0') && (machine->flag & BIT_P))
//			pad_n_str(str, machine, literal);
////		else
////			pad_n_str(str, machine, len);
//		return ;
//	}
