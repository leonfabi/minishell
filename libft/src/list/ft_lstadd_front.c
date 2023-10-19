/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:29:41 by makurz            #+#    #+#             */
/*   Updated: 2023/04/21 08:53:22 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add a 'new_list'-node to the beginning of a list.
void	ft_lstadd_front(t_list **lst, t_list *new_list)
{
	if (lst == NULL || new_list == NULL)
		return ;
	new_list->next = *lst;
	*lst = new_list;
}
