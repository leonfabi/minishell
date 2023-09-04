#include "minishell.h"

t_bool	check_redirect(t_type type)
{
	if (type == TOKEN_LESS)
		return (TRUE);
	if (type == TOKEN_GREATER)
		return (TRUE);
	if (type == TOKEN_DGREATER)
		return (TRUE);
	if (type == TOKEN_DLESS)
		return (TRUE);
	return (FALSE);
}

t_bool	check_arguments(t_type type)
{
	if (type == TOKEN_WORD)
		return (TRUE);
	if (type == TOKEN_DQUOTE)
		return (TRUE);
	if (type == TOKEN_QUOTE)
		return (TRUE);
	return (FALSE);
}

t_bool	check_metachars(t_type type)
{
	if (type == TOKEN_PIPE)
		return (TRUE);
	return (FALSE);
}

t_cmd	*select_redirect(t_cmd *subcmd, t_dlist *tok_list, char **env)
{
	t_token		*redir;
	t_token		*file;

	redir = get_token(tok_list);
	file = get_token(tok_list->next);
	if (redir->type == TOKEN_LESS)
		return (redircmd(subcmd, redir, file, env));
	if (redir->type == TOKEN_GREATER)
		return (redircmd(subcmd, redir, file, env));
	if (redir->type == TOKEN_DGREATER)
		return (redircmd(subcmd, redir, file, env));
	if (redir->type == TOKEN_DLESS)
		return (redircmd(subcmd, redir, file, env));
	return (NULL);
}

t_bool	correct_token(t_type type)
{
	if (type == TOKEN_DLESS)
		return (FALSE);
	if (type == TOKEN_DGREATER)
		return (FALSE);
	if (type == TOKEN_LESS)
		return (FALSE);
	if (type == TOKEN_GREATER)
		return (FALSE);
	if (type == TOKEN_PIPE)
		return (FALSE);
	return (TRUE);
}
