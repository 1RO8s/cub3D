/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:48:53 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/01 21:19:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		result[i] = f(i, *s);
		i++;
		s++;
	}
	result[i] = '\0';
	return (result);
}
