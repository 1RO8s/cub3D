/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:57:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:30:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

unsigned long long	unsign_int(t_sm *machine)
{
	unsigned int	num;

	num = va_arg(*(machine->ap), unsigned int);
	return ((unsigned long long)num);
}
