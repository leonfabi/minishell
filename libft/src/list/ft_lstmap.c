/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:45:02 by makurz            #+#    #+#             */
/*   Updated: 2023/04/21 08:52:18 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Creates a copy of the list 'lst' and applies the function 'f'
// to the content of it. Frees the list if memory allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(NULL);
	head->content = (*f)(lst->content);
	tmp = head;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (head);
}
