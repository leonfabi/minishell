#include "libft.h"
#include "defines.h"
#include "parser.h"

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
