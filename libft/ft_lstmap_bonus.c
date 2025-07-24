/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:01:15 by alvalien          #+#    #+#             */
/*   Updated: 2024/10/02 21:25:51 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_clear_if_error(t_list **new_list, void (*del)(void *))
{
	ft_lstclear(new_list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*content_map;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content_map = f(lst->content);
		if (!content_map)
			return (ft_clear_if_error(&new_list, del));
		node = ft_lstnew(content_map);
		if (!node)
		{
			del(content_map);
			return (ft_clear_if_error(&new_list, del));
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
