/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:26:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/20 12:29:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char const *sep)
{
	static char	*next_token;
	char		*start;
	char		*end;

	if (sep == NULL)
		return (NULL);
	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	start = next_token;
	while (*start != '\0' && ft_strchr(sep, *start) != NULL)
		start++;
	if (*start == '\0')
		return (NULL);
	end = start + 1;
	while (*end != '\0' && ft_strchr(sep, *end) == NULL)
		end++;
	next_token = end + (*end != '\0');
	*end = '\0';
	return (start);
}
