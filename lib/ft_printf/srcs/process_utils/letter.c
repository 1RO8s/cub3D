/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:53:40 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 10:53:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"

int	letter(const char *input, t_sm *machine)
{
	if (*input == '%')
		machine->state = FLAG;
	else
	{
		add_to_buff(*input, machine);
		if (machine->state == ERROR)
			return (-1);
	}
	return (1);
}
//#include <stdio.h> // deleate this !!!!!!!!!!  (used for debug)
//		printf("cur = '%c' | state = LETTER\n", *input);
//
//void	add_to_buff(char c, t_sm *machine);
