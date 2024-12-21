/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:13:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/20 11:29:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos;

	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0 && *haystack != '\0')
	{
		if (*haystack == *needle)
		{
			pos = 0;
			while (needle[pos] != '\0'
				&& len > pos && haystack[pos] == needle[pos])
				pos++;
			if (needle[pos] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
