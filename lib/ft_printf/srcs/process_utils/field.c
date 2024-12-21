/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:39:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 10:52:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "process.h"

int	field(const char *input, t_sm *machine)
{
	static t_f_field	f_field[NB_FIELD] = {
		width, precision};
	int					size;
	int					i;

	size = 0;
	i = 0;
	while (i < NB_FIELD)
	{
		size += f_field[i](&input[size], machine);
		if (machine->state == ERROR)
			return (-1);
		i++;
	}
	machine->state = PREFIX;
	return (size);
}
//Debug code
//
//Notes "process.h"
//
//# define NB_FIELD	2
