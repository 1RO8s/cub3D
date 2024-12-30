/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:41:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/25 15:10:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "formalize.h"
#include "libft.h"

void	character(t_sm *machine)
{
	char	str[2];

	ft_bzero(str, 2);
	str[0] = (char)va_arg(*(machine->ap), int);
	formalize(str, machine);
}
