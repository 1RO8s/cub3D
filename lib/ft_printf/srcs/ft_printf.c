/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:49:27 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/18 02:03:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "process.h"

int	ft_printf(const char *input, ...)
{
	t_sm	machine;
	va_list	ap;

	va_start(ap, input);
	initialize_machine(&machine, &ap);
	process(input, &machine);
	if (machine.state != ERROR)
	{
		machine.out = join_to_out(machine.out, machine.buffer, machine.len);
		if (machine.out == NULL)
			return (-1);
		machine.out_size = write(1, machine.out, machine.out_size);
	}
	free(machine.out);
	va_end(ap);
	if (machine.state == ERROR)
		return (-1);
	return (machine.out_size);
}

int	ft_eprintf(const char *input, ...)
{
	t_sm	machine;
	va_list	ap;

	va_start(ap, input);
	initialize_machine(&machine, &ap);
	process(input, &machine);
	if (machine.state != ERROR)
	{
		machine.out = join_to_out(machine.out, machine.buffer, machine.len);
		if (machine.out == NULL)
			return (-1);
		machine.out_size = write(STDERR_FILENO, machine.out, machine.out_size);
	}
	free(machine.out);
	va_end(ap);
	if (machine.state == ERROR)
		return (-1);
	return (machine.out_size);
}
