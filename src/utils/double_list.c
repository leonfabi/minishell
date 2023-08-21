/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:00:50 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/19 17:52:09 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*start;

	start = (t_dlist *)malloc(sizeof(t_dlist));
	if (start == NULL)
		return (error_msg(NULL, \
		"Creating node Memory allocation failed"), NULL);
	start->content = content;
	start->next = NULL;
	start->prev = NULL;
	return (start);
}

int	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*counter;

	if (new == NULL)
		return (FALSE);
	counter = ft_dlstlast(*lst);
	if (counter == NULL)
		return (*lst = new, TRUE);
	counter->next = new;
	new->prev = counter;
	return (TRUE);
}

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;
	t_dlist	*tmp_free;

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
