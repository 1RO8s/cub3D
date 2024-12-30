/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:09:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/25 16:20:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "process.h"
#include "libft.h"

int	precision(const char *input, t_sm *machine)
{
	static char	*str_prec;
	size_t		size;

	str_prec = FIELD_PREC;
	size = 0;
	if (input[size] == *str_prec)
	{
		machine->flag |= BIT_PREC;
		size++;
		if (ft_isdigit(input[size]) != TRUE)
			return (size);
		size += get_field_nbr(&input[size], machine);
	}
	return (size);
}
