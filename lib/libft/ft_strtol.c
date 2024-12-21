/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:15:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/22 20:29:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

static int	get_36based_value(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('A' <= c && c <= 'Z')
		return (c - 'A' + 10);
	else if ('a' <= c && c <= 'z')
		return (c - 'a' + 10);
	else
		return (-1);
}

static int	set_value(char c, long *p_value, int sign, int base)
{
	int		num_value;
	long	value_tmp;

	num_value = get_36based_value(c);
	if (num_value < 0 || base <= num_value)
		return (0 == 1);
	num_value *= sign;
	value_tmp = (*p_value) * base;
	if (sign > 0 && (((LONG_MAX / base) < *p_value)
			|| ((LONG_MAX - value_tmp) < num_value)))
		*p_value = LONG_MAX;
	else if (sign < 0 && (((LONG_MIN / base) > *p_value)
			|| ((LONG_MIN - value_tmp) > num_value)))
		*p_value = LONG_MIN;
	else
	{
		*p_value = value_tmp + num_value;
		return (0 == 0);
	}
	return (0 == 1);
}

static int	get_base(const char **p_str, int base)
{
	if (base == 0)
	{
		if ((*p_str)[0] == '0')
		{
			if ((*p_str)[1] == 'x')
				base = 16;
			else
				base = 8;
		}
		else
			base = 10;
	}
	if (base == 8)
		*p_str += 1;
	if (base == 16)
		*p_str += 2;
	return (base);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	long	sign;
	long	value;

	sign = 1;
	value = 0;
	if (endptr != NULL)
		*endptr = (char *)str;
	if (!((2 <= base && base <= 36) || base == 0))
		return (0);
	while (((9 <= *str && *str <= 13) || *str == ' ') && *str != '\0')
		str++;
	if (*str == '-')
		sign = -1;
	else if (*str != '+' && !(('a' <= *str && *str <= 'z')
			|| ('A' <= *str && *str <= 'Z') || ('0' <= *str && *str <= '9')))
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	base = get_base(&str, base);
	while (set_value(*str, &value, sign, base))
		str++;
	if (endptr != NULL)
		*endptr = (char *)str;
	return (value);
}
