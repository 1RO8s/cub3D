/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:11 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/14 03:16:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

//void	print_float(int fd, double number, int precision)
//{
//	int		integer_part;
//	double	fractional_part;
//	int		i;
//	int		digit;
//
//	integer_part = (int)number;
//	fractional_part = number - integer_part;
//	if (precision > DBL_DIG)
//		precision = DBL_DIG;
//	ft_dprintf(fd, "%d.", integer_part);
//	i = 0;
//	while (i < PRECISION)
//	{
//		fractional_part *= 10;
//		digit = (int)fractional_part;
//		ft_dprintf(fd, "%d", digit);
//		fractional_part -= digit;
//		i++;
//	}
//	return ;
//}

static char	*convert_integer_to_string(long long int_part, char *str)
{
	char	int_str[20];
	int		int_len;
	int		i;

	int_len = 0;
	int_str[int_len++] = '0' + (int_part % 10);
	int_part /= 10;
	while (int_part > 0)
	{
		int_str[int_len++] = '0' + (int_part % 10);
		int_part /= 10;
	}
	i = int_len - 1;
	while (i >= 0)
	{
		*str++ = int_str[i];
		i--;
	}
	return (str);
}

void	double_to_string(double value, char *str, size_t n)
{
	long long	int_part;
	double		frac_part;
	int			i;
	int			digit;

	ft_bzero((void *)str, n);
	if (value < 0)
	{
		*str++ = '-';
		value = -value;
	}
	int_part = (long long)value;
	frac_part = value - int_part;
	str = convert_integer_to_string(int_part, str);
	*str++ = '.';
	i = 0;
	while (i < PRECISION)
	{
		frac_part *= 10;
		digit = (int)frac_part;
		*str++ = '0' + digit;
		frac_part -= digit;
		i++;
	}
	*str = '\0';
}

//int	count_precision(double number)
//{
//    int precision = 0;
//
//    // Get the fractional part by subtracting the integer part
//    double fractional_part = number - (int)number;
//
//	printf("\t[%f]\n", fractional_part);
//    // Count decimal places until the fractional part becomes close to zero
//    while (fractional_part > 0) {
//        fractional_part *= 10;
//		// Get the next digit in the fractional part
//        int digit = (int)fractional_part;
//        fractional_part -= digit;          // Remove the extracted digit
//        precision++;                       // Increment precision count
//
//        // Stop if the fractional part becomes close enough to zero
//        if (fabs(fractional_part) < 1e-10) {
//            break;
//        }
//		printf("\t[%f]\n", fractional_part);
//    }
//
//    return precision;
//}

//cc print_float.c ../../ft_printf/libftprintf.a -I../../../includes
//	-I../../minilibx-linux -I../../libft
//	-I../../ft_printf/includes -I../includes
//int main(void)
//{
//// ---------- double_to_string ---------
//    char str[32];
//    //double value = -12345.678901234;
//    double value = -10.678901234;
//    //int precision = 6;  // Number of decimal places to include
//
//	printf("value\t\t\t[%f] ... %%f\n", value);
//    double_to_string(value, str, sizeof(str));
//
//    printf("Double as string:\t[%s]\n", str);
//	//ft_bzero((void *)str, sizeof(str));
//    //printf("Double as string: [%s] (after)\n", str);
//	printf("int[%lu] long[%lu] longlong[%lu] double[%lu] sizeof(str)[%lu]\n",
//		sizeof(int), sizeof(long), sizeof(long long),
//		sizeof(double), sizeof(str));
//
//    return 0;
//// ---------- print_float ---------
////	int	precision = 0;
////	double	number = 1234.56789;
////	precision = 10;
////	printf("number[%f] precision[%d]\n", number, precision);
////	print_float(STDOUT_FILENO, number, precision);
//// ---------- count precision ---------
////	int	precision = 0;
////	double	number = 1234.56789;
////	precision = count_precision(number);
////	printf("number[%f] precision[%d]\n", number, precision);
//// ---------- macro ----------
////	printf("size[%lu]\n", sizeof(double));
////	printf("Max double value:\t\t[%e] [%f]\n", DBL_MAX, DBL_MAX);
////	printf("Max flt    value:\t\t[%e] [%f]\n", FLT_MAX, FLT_MAX);
////	printf("Min positive double value:\t[%e] [%f]\n", DBL_MIN, DBL_MIN);
////	//printf("Min negative double value:\t[%e] [%f]\n", DBL_MIN, DBL_MIN);
////	printf("Decimal precision of double:\t[%d] digits\n", DBL_DIG);
////	printf("Decimal precision of double:\t[%d] digits\n", LDBL_DIG);
////	printf("Decimal precision of double:\t[%d] digits\n", FLT_DIG);
//}
