/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:51:40 by makurz            #+#    #+#             */
/*   Updated: 2023/09/05 10:24:21 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the size of the list 'lst'.
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*i;

	if (lst == NULL)
		return (0);
	i = lst;
	size = 1;
	while (NULL != i->next)
	{
		++size;
		i = i->next;
	}
	return (size);
}
