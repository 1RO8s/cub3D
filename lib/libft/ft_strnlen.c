/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:47:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/26 21:24:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	if (!maxlen)
		return (len);
	while (*s)
	{
		if (len == maxlen)
			break ;
		len++;
		s++;
	}
	return (len);
}
