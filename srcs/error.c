/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:05:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/07/28 21:45:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

static void	error_message(int error_code)
{
	static char	*msg[ERR_NUM] = {MSG_MLX, MSG_WIN, MSG_MAP};

	ft_fprintf(stderr, msg[error_code]);
}

void	error_fdf(int error_code)
{
	error_message(error_code);
	exit(error_code);
}

void	ft_errno_exit(char *cause)
{
	int		error_number;
	char	*error_message;

	error_number = errno;
	error_message = strerror(error_number);
	ft_fprintf(stderr, "%s: %s: %s\n", NAME, cause, error_message);
	exit (1);
}

void	ft_perror_exit(char *message)
{
	perror(message);
	exit (1);
}
