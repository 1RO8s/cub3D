/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:02:10 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/16 04:14:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_duplicate_info(int variable, int flag_to_check, const char *line)
{
	if (check_for_not_matching_bit(variable, flag_to_check) == 0x00)
	{
		put_error_msg(line, EMSG_ENTRY_DUP);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
