/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:52:47 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 11:29:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "process.h"

void	adjust_sign(char *str, t_sm *machine)
{
	if ((machine->flag & BIT_PLUSE) != FALSE)
		str[0] = '+';
	else
		str[0] = ' ';
}
