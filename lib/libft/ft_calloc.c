/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:09:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/01/23 16:46:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p_ret;
	size_t	total;

	total = count * size;
	if (size != 0 && total / size != count)
		return (NULL);
	if (total == 0)
		return (ft_calloc(1, 1));
	p_ret = malloc(total);
	if (!(p_ret == NULL))
		ft_bzero(p_ret, total);
	return (p_ret);
}
