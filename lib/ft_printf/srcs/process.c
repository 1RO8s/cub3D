/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:19:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 10:49:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "process.h"
#include "libft.h"

void	process(const char *input, t_sm *machine)
{
	static t_f_process	f_process[5] = {letter, flag, field, prefix, type};
	int					ret;

	while (*input != '\0' && input != NULL && machine->state != ERROR)
	{
		ret = f_process[machine->state](input, machine);
		if (ret >= 0)
			input += ret;
	}
}
// following code for debug
//#include <stdio.h>
//#include <unistd.h>
//	printf("printf(out):\t\t\t%s\n", machine.out);
//	printf("write(1, out, size):\t");
//	printf("\n");
//	free(machine.out);
//	printf("printf(out):\t\t\t%s\tafter free\n", machine.out);
// following code is void
//	machine.out = ft_strjoin_free(machine.out, machine.buffer);
//	write(1, machine.out, machine.out_size);
	//while (machine.state != END)
