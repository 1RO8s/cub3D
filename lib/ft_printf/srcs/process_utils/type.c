/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:43:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 10:54:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "process.h"
#include "conversion.h"

int	type(const char *input, t_sm *machine)
{
	static char	*str_type;
	int			i;
	int			bit_offset;

	str_type = ALL_TYPE;
	i = 0;
	bit_offset = NB_FLAG + NB_FIELD + 1 + NB_PREFIX;
	while (i < NB_TYPE)
	{
		if (ft_strnequ(input, str_type + i, 1) == TRUE)
		{
			machine->flag |= (1 << i) << bit_offset;
			conversion(machine);
			if (machine->state == ERROR)
				return (-1);
			machine->flag = 0;
			machine->width = 0;
			machine->prec = 0;
			machine->state = LETTER;
			return (1);
		}
		i++;
	}
	machine->state = ERROR;
	return (-1);
}
//	debug code
//#include <stdio.h>// for debug
//#include <stdlib.h>// for debug
//	char *flag_bin = ft_itoa_binary(machine->flag);// for debug
//	printf("cur = '%c' | state = TYPE \t| flag = %s (%#x)\n"
//		, *input, flag_bin, machine->flag);// for debug
//	printf("------ call conversion(machine) ------ diouxXpsc%%\n");// for debug
//	printf("buffer: %s\tafter conversion\n", machine->buffer);// for debug
//	free(flag_bin);// for debug
