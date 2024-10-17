/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_is_hit_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:48:47 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/17 15:56:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_is_hit_flag(t_game *game, int bit)
{
	int		fd;
	char	*bin_bit;
	char	*bin_flag;

	if (IS_DEBUG != true)
		return ;
	fd = game->debug.fd;
	dprintf(fd, ">>> is_hit_flag() == true\n");
	bin_flag = ft_itoa_binary(game->frame.flag);
	if (bin_flag == NULL)
	{
		dprintf(STDERR_FILENO, "Error: in debug_is_hit_flag\n");
		return ;
	}
	dprintf(fd, "\tflag[%s]\n", bin_flag);
	bin_bit = ft_itoa_binary(bit);
	if (bin_bit == NULL)
	{
		dprintf(STDERR_FILENO, "Error: in debug_is_hit_flag\n");
		free(bin_bit);
		return ;
	}
	dprintf(fd, "\tbit [%s]\n", bin_flag);
	free(bin_bit);
	free(bin_flag);
}
// This is a function for debugging prints,
// so the game will not end even if a system error occurs.
