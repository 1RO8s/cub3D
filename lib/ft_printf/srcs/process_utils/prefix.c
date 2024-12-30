/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:40:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 10:53:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "process.h"

int	prefix(const char *input, t_sm *machine)
{
	static char	*str_prefix[NB_PREFIX] = {
		PREFIX_HH, PREFIX_LL, PREFIX_H, PREFIX_L};
	int			size;
	int			i;

	size = 0;
	i = 0;
	while (i < NB_PREFIX)
	{
		if (i < 2)
			size = 2;
		else
			size = 1;
		if (ft_strnequ(input, str_prefix[i], size) == TRUE)
		{
			machine->flag |= (1 << i) << 8;
			return (size);
		}
		i++;
	}
	machine->state = TYPE;
	return (0);
}
