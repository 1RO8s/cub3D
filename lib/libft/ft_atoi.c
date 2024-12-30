/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:19:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/22 16:21:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

long	ft_strtol(const char *str, char **endptr, int base);

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, NULL, 10));
}
