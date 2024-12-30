/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:20:37 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/18 11:49:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	int				d;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (dst == src || n == 0)
		return (dst);
	if (to > from)
	{
		to += n - 1;
		from += n - 1;
		d = -1;
	}
	else
		d = +1;
	while (n-- > 0)
	{
		*(unsigned char *)to = *(unsigned char *)from;
		to += d;
		from += d;
	}
	return (dst);
}
