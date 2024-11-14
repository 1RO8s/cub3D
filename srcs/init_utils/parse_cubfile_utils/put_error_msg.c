/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:42:41 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/15 00:42:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_error_msg(const char *entry, const char *msg)
{
	ft_dprintf(STDERR_FILENO, ERR_PROMPT);
	while (*entry != ' ' && *entry != '\0' && *entry != '\n')
	{
		write(STDERR_FILENO, entry, 1);
		entry++;
	}
	ft_dprintf(STDERR_FILENO, ": %s\n", msg);
}
