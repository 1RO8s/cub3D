/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:15:38 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/20 16:47:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	looking_for;

	if (n == 0)
		return (NULL);
	p_s = (unsigned char *)s;
	looking_for = (unsigned char)c;
	while (--n > 0 && *p_s != looking_for)
		p_s++;
	if (*p_s == looking_for)
		return (p_s);
	else
		return (NULL);
}
