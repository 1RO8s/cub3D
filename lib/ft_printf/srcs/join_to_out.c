/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_to_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:48:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/25 09:50:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*join_to_out(const char *s1, const char *s2, size_t len2)
{
	char	*str;
	size_t	len1;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	len1 = ft_strlen(s1);
	str = ft_strnew(len1 + len2);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_memcpy(&str[len1], s2, len2);
	free((void *)s1);
	return (str);
}
