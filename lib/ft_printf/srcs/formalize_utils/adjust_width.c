/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:15:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/29 22:48:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "formalize.h"
#include "libft.h"

static void	seq_zero(const char *str, t_sm *machine)
{
	int	len;

	len = (int)ft_strlen(str);
	add_to_buff(str[0], machine);
	if (machine->state == ERROR)
		return ;
	if ((machine->flag & BIT_LEFT) != FALSE)
	{
		pad_n_str(&str[1], machine, len - 1);
		if (machine->state == ERROR)
			return ;
		pad_width(machine, len);
	}
	else
	{
		pad_width(machine, len);
		if (machine->state == ERROR)
			return ;
		pad_n_str(&str[1], machine, len - 1);
	}
}

static void	case_signed_num(const char *str, t_sm *machine)
{
	int	len;

	if ((machine->flag & BIT_ZERO) != FALSE)
	{
		seq_zero(str, machine);
		return ;
	}
	len = ft_strlen(str);
	if ((machine->flag & BIT_LEFT) != FALSE)
	{
		pad_n_str(str, machine, len);
		if (machine->state == ERROR)
			return ;
		pad_width(machine, len);
	}
	else
	{
		pad_width(machine, len);
		if (machine->state == ERROR)
			return ;
		pad_n_str(str, machine, len);
	}
}

static void	case_other(const char *str, t_sm *machine)
{
	size_t	len;

	len = ft_strlen(str);
	if ((machine->flag & BIT_C) && str[0] == '\0')
		len = 1;
	if ((machine->flag & BIT_LEFT) != FALSE)
	{
		pad_n_str(str, machine, len);
		if (machine->state == ERROR)
			return ;
		pad_width(machine, len);
	}
	else
	{
		pad_width(machine, len);
		if (machine->state == ERROR)
			return ;
		pad_n_str(str, machine, len);
	}
}

static void	case_pad_zero(const char *str, t_sm *machine)
{
	int	literal;
	int	len;
	int	i;

	literal = 2;
	len = ft_strlen(str);
	pad_n_str(str, machine, literal);
	if (machine->state == ERROR)
		return ;
	i = 0;
	while ((i + len < machine->width) && (machine->state != ERROR))
	{
		add_to_buff('0', machine);
		i++;
	}
	pad_n_str(&str[literal], machine, len - literal);
}

void	adjust_width(const char *str, t_sm *machine)
{
	if ((machine->flag & (BIT_PLUSE | BIT_SPACE))
		|| ((machine->flag & (BIT_D | BIT_I)) && str[0] == '-') != FALSE)
		case_signed_num(str, machine);
	else if ((machine->flag & BIT_ZERO) && (~machine->flag & BIT_LEFT)
		&& ((machine->flag & (BIT_P | BIT_X | BIT_XMAJ))
			&& (machine->flag & BIT_HASH)) != FALSE)
		case_pad_zero(str, machine);
	else
		case_other(str, machine);
}
//this code moved to pad_width.c
//	while (len + i < machine->width && (machine->state != ERROR))
//	{
//		add_to_buff(' ', machine);
//		i++;
//	}
//this code moved to pad_n_str.c
//	size_t	i;
//
//	i = 0;
//	while (i < len && (machine->state != ERROR))
//	{
//		add_to_buff(str[i], machine);
//		i++;
//	}
//this code is error handle
//	if (machine->state == ERROR)
//		return ;
//debug code
//#include <stdio.h>// for debug
//	printf("%d:width\n", machine->width);// for debug
//	printf("%d:precision\n", machine->prec);// for debug
//	printf("%d:len\n", len);// for debug
//	printf("%s:str\n", str);// for debug
//	char *flag_bin = (char *)ft_itoa_binary(machine->flag);// for debug
//	printf("%s:flag_bin\t%#x:flag\n", flag_bin, machine->flag);// for debug
//	free(flag_bin);// for debug
