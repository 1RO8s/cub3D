/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:47:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/02 17:03:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isinteger.c
 * @brief Checks if a given string represents a valid integer
 */
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

/**
 * @brief Checks if a given string represents a valid integer
 *
 * @param str is target to check
 *
 * @return 1(true):str is valid string, 0(false):str is invalid string
 */
bool	ft_isinteger(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
//
//#include <stdio.h>
//#define VALIDINT "+12345"
//#define INVALIDINT "12a45"
//
//int	main(void)
//{
//	const char	*validInt = VALIDINT;
//	const char	*invalidInt = INVALIDINT;
//	bool		isValid;
//
//	isValid = ft_isinteger(validInt);
//	printf("[%s] Is validInt a valid integer? %s\n",
//		validInt, isValid ? "Yes" : "No");
//	isValid = ft_isinteger(invalidInt);
//	printf("[%s] Is invalidInt a valid integer? %s\n",
//		invalidInt, isValid ? "Yes" : "No");
//	return (0);
//}
