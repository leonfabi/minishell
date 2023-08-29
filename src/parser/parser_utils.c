#include "minishell.h"

t_token	*get_token(t_dlist *token)
{
	t_token		*tok;

	tok = (t_token *)token->content;
	return (tok);
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

t_bool	nullterminate(t_dlist **token)
{
	t_dlist		*run;
	t_token		*tok;

	run = *token;
	while (((t_token *)run->content)->type != TOKEN_EOF)
	{
		tok = get_token(run);
		if (correct_token(tok->type) == TRUE)
			*(tok->value + tok->value_length) = '\0';
		run = run->next;
	}
	return (TRUE);
}
