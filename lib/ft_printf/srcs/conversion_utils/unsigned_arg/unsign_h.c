/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:01:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:29:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

unsigned long long	unsign_h(t_sm *machine)
{
	unsigned short	num;

	num = (unsigned short)va_arg(*(machine->ap), int);
	return ((unsigned long long)num);
}
