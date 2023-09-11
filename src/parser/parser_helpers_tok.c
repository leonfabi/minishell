#include "minishell.h"

int	get_token_length(t_dlist *token)
{
	t_token		*tok;

	tok = (t_token *)token->content;
	return (tok->len);
}

char	*get_token_value(t_dlist *token)
{
	t_token		*tok;

	tok = (t_token *)token->content;
	return (tok->value);
}

t_type	get_token_type(t_dlist *token)
{
	t_token		*tok;

	tok = (t_token *)token->content;
	return (tok->type);
}

t_token	*get_token(t_dlist *token)
{
	return ((t_token *)token->content);
}
