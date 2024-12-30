/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:03:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:30:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

unsigned long long	unsign_l(t_sm *machine)
{
	unsigned long	num;

	num = va_arg(*(machine->ap), unsigned long);
	return ((unsigned long long)num);
}
