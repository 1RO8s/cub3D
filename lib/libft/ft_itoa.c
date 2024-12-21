/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:39:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/31 13:56:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_itoa_len(long n_long)
{
	int		len;

	len = 0;
	if (n_long == 0)
		len = 1;
	else
	{
		while (n_long > 0)
		{
			n_long /= 10;
			len++;
		}
	}
	return (len);
}

static int	ft_itoa_sign(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	long	n_long;

	n_long = n;
	sign = ft_itoa_sign(n);
	n_long *= sign;
	len = ft_itoa_len(n_long);
	str = (char *)malloc(sizeof(char) * (len + (sign < 0) + 1));
	if (str == NULL)
		return (NULL);
	if (sign < 0)
		str[0] = '-';
	str[len + 1 - (sign > 0)] = '\0';
	while (len)
	{
		str[len - (sign > 0)] = n_long % 10 + '0';
		n_long /= 10;
		len--;
	}
	return (str);
}
