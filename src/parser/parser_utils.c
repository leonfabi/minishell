#include "minishell.h"

t_token	*get_token(t_dlist *token)
{
	return ((t_token *)token->content);
}

static t_bool	correct_token(t_type type)
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

t_bool	nulterminate(t_dlist **token)
{
	t_dlist		*run;
	t_token		*tok;

	run = *token;
	while (get_token_type(run) != TOKEN_EOF)
	{
		tok = get_token(run);
		if (correct_token(tok->type) == TRUE)
			*(tok->value + tok->value_length) = '\0';
		run = run->next;
	}
	return (TRUE);
}
