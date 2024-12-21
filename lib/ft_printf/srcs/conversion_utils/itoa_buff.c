/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:41:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/25 15:37:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "libft.h"
#include <stddef.h>

static char	get_digit(unsigned long num, int base, t_sm *machine)
{
	num %= base;
	if (base == 8 || base == 10 || num < 10)
		return (num + '0');
	else
	{
		num -= 10;
		if ((machine->flag & (BIT_X | BIT_P)) != FALSE)
			return (num + 'a');
		else
			return (num + 'A');
	}
}

static size_t	itoa_len(unsigned long num, long base)
{
	size_t	len;

	len = 1;
	if (num < (unsigned long)base)
		return (len);
	while (num >= (unsigned long)base)
	{
		len++;
		num /= base;
	}
	return (len);
}

char	*itoa_buff(unsigned long long num, char *str, int base, t_sm *machine)
{
	size_t	len;
	size_t	i;

	len = itoa_len(num, base);
	i = 1;
	while (len > i - 1)
	{
		str[len - i] = get_digit(num, base, machine);
		num /= base;
		i++;
	}
	return (str);
}
