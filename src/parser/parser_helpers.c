#include "minishell.h"

t_bool	check_tok_connection(t_token *tok)
{
	t_type		type;

	type = tok->type;
	if (tok->type == TOKEN_WORD && ft_strchr(SPACE, *(tok->value + tok->len)))
		return (TRUE);
	else if (tok->type & (TOKEN_DQUOTE | TOKEN_QUOTE))
	{
		if (ft_strchr(SPACE, *(tok->value + tok->len + 1)))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	check_redirect(t_type type)
{
	if (type & (TOKEN_LESS | TOKEN_DLESS))
		return (TRUE);
	if (type & (TOKEN_GREATER | TOKEN_DGREATER))
		return (TRUE);
	return (FALSE);
}

t_bool	check_arguments(t_type type)
{
	if (type & (TOKEN_WORD | TOKEN_QUOTE | TOKEN_DQUOTE))
		return (TRUE);
	return (FALSE);
}

t_bool	check_metachars(t_type type)
{
	if (type == TOKEN_PIPE)
		return (TRUE);
	return (FALSE);
}

t_cmd	*select_redirect(t_cmd *subcmd, t_dlist **list, char **env)
{
	t_token		*redir;

	redir = get_token(*list);
	*list = (*list)->next;
	if (redir->type == TOKEN_LESS)
		return (redircmd(subcmd, redir, list, env));
	if (redir->type == TOKEN_GREATER)
		return (redircmd(subcmd, redir, list, env));
	if (redir->type == TOKEN_DGREATER)
		return (redircmd(subcmd, redir, list, env));
	if (redir->type == TOKEN_DLESS)
		return (redircmd(subcmd, redir, list, env));
	return (NULL);
}
