/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:33 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/18 14:45:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*save;

	ch = (char)c;
	save = (char *)0;
	while (1)
	{
		if (*s == ch)
			save = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (save);
}
