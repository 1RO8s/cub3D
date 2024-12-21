/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_hh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:23:17 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 14:35:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

long long	sign_hh(t_sm *machine)
{
	signed char	num;

	num = (signed char)va_arg(*(machine->ap), int);
	return ((long long)num);
}
//note
//num = (short char)va_arg(*(machine->ap), short char);
//complie error:	this va_arg has undefined behavior
//					because type short will be promoted to int.
