/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:00:50 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/09 17:25:27 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*start;

	start = (t_dlist *)malloc(sizeof(t_dlist));
	if (start == NULL)
		return (NULL);
	start->content = content;
	start->next = NULL;
	start->prev = NULL;
	return (start);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*counter;

	counter = ft_lstlast(*lst);
	if (counter != NULL)
	{
		counter->next = new;
		new->prev = counter;
	}
	else
		*lst = new;
}