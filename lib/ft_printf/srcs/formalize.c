/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:31:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/30 11:41:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "process.h"
#include "conversion.h"
#include "formalize.h"
#include "libft.h"

void	formalize(const char *str, t_sm *machine)
{
	int		adjust_flag;
	int		len;

	adjust_flag = BIT_WIDTH | BIT_PREC;
	if ((machine->flag & adjust_flag) != FALSE)
		adjust(str, machine);
	else
	{
		if ((machine->flag & BIT_C) && str[0] == '\0')
			pad_n_str(str, machine, 1);
		else
		{
			len = (int)ft_strlen(str);
			if ((machine->flag & BIT_HASH) && (str[2] == '0'))
			{
				pad_n_str(&str[2], machine, len - 2);
				return ;
			}
			pad_n_str(str, machine, len);
		}
	}
}
