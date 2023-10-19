/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:44:02 by makurz            #+#    #+#             */
/*   Updated: 2023/05/15 19:56:47 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and every successor of that node.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_free;

	tmp = NULL;
	tmp_free = NULL;
	if (lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		(*del)(tmp->content);
		tmp_free = tmp;
		tmp = tmp->next;
		free(tmp_free);
	}
	*lst = NULL;
}
