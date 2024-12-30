/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:43:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/26 19:58:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, dstsize);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	ft_strncat(dst, src, dstsize - dstlen - 1);
	return (dstlen + srclen);
}
