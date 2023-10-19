/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:15:41 by makurz            #+#    #+#             */
/*   Updated: 2023/05/16 14:00:04 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add a 'new_node'-node to the end of a list.
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	last = NULL;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_node;
	}
}
