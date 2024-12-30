/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:07:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/27 22:51:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
			start++;
	while (ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_strndup(s1 + start, end - start));
}
