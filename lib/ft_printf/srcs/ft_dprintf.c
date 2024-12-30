/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:55:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/07 18:55:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "process.h"

static void	handle_error(const char *cause)
{
	ft_dprintf(STDERR_FILENO, "%s\n", cause);
	exit(1);
}

static int	set_stdout_fd(int fd)
{
	int	original_stdout_fd;

	original_stdout_fd = dup(STDOUT_FILENO);
	if (original_stdout_fd == -1)
		handle_error("dup");
	if (dup2(fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	return (original_stdout_fd);
}

int	ft_dprintf(int fd, const char *input, ...)
{
	t_sm	machine;
	va_list	ap;
	int		original_stdout_fd;

	original_stdout_fd = set_stdout_fd(fd);
	va_start(ap, input);
	initialize_machine(&machine, &ap);
	process(input, &machine);
	if (machine.state != ERROR)
	{
		machine.out = join_to_out(machine.out, machine.buffer, machine.len);
		if (machine.out == NULL)
			return (-1);
		machine.out_size = write(1, machine.out, machine.out_size);
	}
	free(machine.out);
	va_end(ap);
	if (machine.state == ERROR)
		return (-1);
	if (dup2(original_stdout_fd, STDOUT_FILENO) == -1)
		handle_error("dup2");
	close(original_stdout_fd);
	return (machine.out_size);
}
