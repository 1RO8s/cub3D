/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:05:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/02/08 20:43:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (new_list == NULL)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	temp = new_list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = ft_lstnew(f(lst->content));
		if (temp->next == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new_list);
}
