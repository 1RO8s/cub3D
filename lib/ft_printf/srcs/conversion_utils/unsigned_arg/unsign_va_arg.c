/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_va_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:44:14 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/07 11:48:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "process.h"
#include "conversion.h"
#include "va_arg.h"

unsigned long long	unsign_va_arg(t_sm *machine)
{
	unsigned long long	num;
	int					i;
	static t_f_u_va_arg	f_u_va_arg[5] = {unsign_hh, unsign_ll,
		unsign_h, unsign_l, unsign_int};

	i = 0;
	while (i < NB_PREFIX)
	{
		if ((machine->flag & (1 << i << 8)) != FALSE)
		{
			num = f_u_va_arg[i](machine);
			return (num);
		}
		i++;
	}
	num = (unsigned long long)f_u_va_arg[i](machine);
	return (num);
}
//debug code
//#include <stdio.h>//for debug
//#include "libft.h"//for debug
//	printf("%d:flag\n", machine->flag);
