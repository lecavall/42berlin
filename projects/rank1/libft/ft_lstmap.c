/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:30:21 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/12 18:19:52 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_item;
	void	*new_content;

	if (!lst || !f || !del)
	{
		return (NULL);
	}
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_item = ft_lstnew(new_content);
		if (new_item == NULL)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_item);
		lst = lst->next;
	}
	return (new_list);
}
