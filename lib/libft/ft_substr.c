/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:53:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/26 15:06:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	return (ft_strndup(s + start, len));
}
