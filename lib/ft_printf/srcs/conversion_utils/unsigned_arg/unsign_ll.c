/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:05:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:30:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

unsigned long long	unsign_ll(t_sm *machine)
{
	unsigned long long	num;

	num = va_arg(*(machine->ap), unsigned long long);
	return (num);
}
