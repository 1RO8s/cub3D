/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:06:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/04 16:04:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	if (lst == NULL)
		return (count);
	temp = lst;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
