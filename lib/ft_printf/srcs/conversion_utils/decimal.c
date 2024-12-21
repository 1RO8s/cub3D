/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:15:55 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 14:49:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "process.h"
#include "conversion.h"
#include "va_arg.h"
#include "formalize.h"
#include "libft.h"

static	size_t	get_digit(long long num)
{
	size_t	len;

	len = 1;
	if (num < 0)
	{
		len++;
		if (num > 9)
		{
			len++;
			num = -1 * (num / 10);
		}
		else
			num *= -1;
	}
	while (num / 10 > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static void	num_to_str(long long num, char *str, t_sm *machine)
{
	long long	tmp_num;
	size_t		len;

	tmp_num = num;
	len = get_digit(num);
	if (num < 0)
	{
		str[0] = '-';
		str[len - 1] = -1 * (num % 10) + '0';
		tmp_num = -1 * (num / 10);
		if (tmp_num > 0)
			itoa_buff(tmp_num, &str[num < 0], 10, machine);
	}
	else if ((machine->flag & (BIT_SPACE | BIT_PLUSE)) != FALSE)
	{
		adjust_sign(str, machine);
		itoa_buff(num, &str[num >= 0], 10, machine);
	}
	else
		itoa_buff(num, str, 10, machine);
}

void	decimal(t_sm *machine)
{
	char		str[42];
	long long	num;

	ft_bzero(str, 42);
	num = sign_va_arg(machine);
	if (!((machine->flag & BIT_PREC) && (machine->prec == 0) && (num == 0)))
		num_to_str(num, str, machine);
	formalize(str, machine);
}
// debug code
//#include <stdio.h>// for debug
//	printf("|num:%d|", (int)num);// for debug
//	printf("|len:%d|", (int)len);// for debug
//	printf("|str:%s|", str);// for debug
