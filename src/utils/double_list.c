#include "lexer.h"

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

t_bool	ft_dlstadd_back(t_dlist **lst, t_dlist *add)
{
	t_dlist	*counter;

	if (add == NULL)
		return (FALSE);
	counter = ft_dlstlast(*lst);
	if (counter == NULL)
		return (*lst = add, TRUE);
	counter->next = add;
	add->prev = counter;
	return (TRUE);
}

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;

	tmp = NULL;
	if (lst == NULL)
		return ;
	while ((*lst)->prev != NULL)
		*lst = (*lst)->prev;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		(*del)(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
