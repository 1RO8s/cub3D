/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_hh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:59:28 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:30:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

unsigned long long	unsign_hh(t_sm *machine)
{
	unsigned char	num;

	num = (unsigned char)va_arg(*(machine->ap), int);
	return ((unsigned long long)num);
}
