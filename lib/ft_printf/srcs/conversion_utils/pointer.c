/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:42:12 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/25 17:08:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include "ft_printf.h"
#include "conversion.h"
#include "formalize.h"
#include "libft.h"

void	pointer(t_sm *machine)
{
	char			str[42];
	uintptr_t		p;
	int				base;

	ft_bzero(str, 42);
	base = 0x10;
	p = va_arg(*(machine->ap), uintptr_t);
	str[0] = '0';
	str[1] = 'x';
	itoa_buff((unsigned long)p, &str[2], base, machine);
	formalize(str, machine);
}
//note
//	p = va_arg(*(machine->ap), uintptr_t);
//		uintptr_t is an integer type.
//this code is not recommended
//	p = va_arg(*(machine->ap), void *);
//		void * is pointer type.
//		it is often used when the type of the pointed-to object is
//		not known at compile time , or when you want to write code
//		that can work with different types of objects.
//	p = va_arg(*(machine->ap), uintptr);
//		uintptr is size and behavior may vary depending
//		on the platform and compiler.
