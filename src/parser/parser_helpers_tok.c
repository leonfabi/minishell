#include "minishell.h"

int	get_token_length(t_dlist *token)
{
	t_token		*tok;

	if (NULL == token)
		return (-1);
	tok = (t_token *)token->content;
	return (tok->len);
}

char	*get_token_value(t_dlist *token)
{
	t_token		*tok;

	if (NULL == token)
		return (NULL);
	tok = (t_token *)token->content;
	return (tok->value);
}

t_type	get_token_type(t_dlist *token)
{
	t_token		*tok;

	if (NULL == token)
		return (TOKEN_EOF);
	tok = (t_token *)token->content;
	return (tok->type);
}

t_token	*get_token(t_dlist *token)
{
	if (NULL == token)
		return (NULL);
	return ((t_token *)token->content);
}
