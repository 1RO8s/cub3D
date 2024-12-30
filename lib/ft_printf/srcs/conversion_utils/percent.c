/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:42:03 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/22 12:11:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "process.h"
#include "conversion.h"
#include "formalize.h"
#include "libft.h"

void	percent(t_sm *machine)
{
	char	str[2];

	ft_bzero(str, 2);
	str[0] = '%';
	formalize(str, machine);
}
//this code moved to formalize.c
//	add_to_buff('%', machine);
