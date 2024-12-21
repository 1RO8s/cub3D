/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:47:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/04 15:13:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isint.c
 * @brief Checks whether the argument str is within
 * the range of INT_MIN and INT_MAX
 */
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "libft.h"

/**
 * @brief Checks whether the argument str is within
 * the range of INT_MIN and INT_MAX
 *
 * @param str is target to check
 *
 * @return 1(true):str is valid string, 0(false):str is invalid string
 */
bool	ft_isint(const char *str)
{
	size_t	i;
	long	num;

	i = 0;
	if (str == NULL || *str == '\0')
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	num = ft_strtol(str, NULL, 10);
	if (num >= INT_MIN && num <= INT_MAX)
		return (true);
	else
		return (false);
}
