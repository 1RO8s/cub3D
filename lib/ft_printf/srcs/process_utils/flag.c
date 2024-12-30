/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:15:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/24 10:52:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "process.h"

int	flag(const char *input, t_sm *machine)
{
	static char	*str_flag[NB_FLAG] = {
		FLAG_ZERO, FLAG_LEFT, FLAG_HASH, FLAG_SPACE, FLAG_PLUSE};
	int			size;
	int			i;

	size = 1;
	i = 0;
	while (i < NB_FLAG)
	{
		if (ft_strnequ(input, str_flag[i], size) == TRUE)
		{
			machine->flag |= (1 << i);
			return (size);
		}
		i++;
	}
	machine->state = FIELD;
	return (0);
}
//Debug code
//#include <stdio.h>
//			char *flag_bin = ft_itoa_binary(machine->flag);
//			printf("cur = '%c' state = FLAG\tflag = '%d'\t%s\n",
//				*input, machine->flag, flag_bin);
//			free(flag_bin);
//
//Notes "process.h"
//# define FLAG_ZERO	"0"
//# define FLAG_LEFT	"-"
//# define FLAG_HASH	"#"
//# define FLAG_SPACE	" "
//# define FLAG_PLUSE	"+"
//
//# define NB_FLAG	5
//
//# define TRUE	1
//# define FALSE	0
