/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:39:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/22 13:12:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_binary(int n)
{
	char	*binary;
	int		i;

	binary = (char *)malloc(sizeof(char) * (16 + 1));
	if (binary == NULL)
		return (NULL);
	i = 0;
	while (i < 16)
	{
		if (n & (0x8000) >> i)
			binary[i] = '1';
		else
			binary[i] = '0';
		i++;
	}
	binary[i] = '\0';
	return (binary);
}
