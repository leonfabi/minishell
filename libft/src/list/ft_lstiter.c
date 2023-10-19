/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:37:57 by makurz            #+#    #+#             */
/*   Updated: 2023/03/27 16:26:27 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function 'f' to the content of 'lst'.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	i = lst;
	while (i)
	{
		(*f)(i->content);
		i = i->next;
	}
}
