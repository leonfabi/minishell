#include "lexer.h"
#include "utils.h"

t_lexer	ft_init_lexer(char *str)
{
	t_lexer	lexer;

	lexer = (t_lexer){
		.start = str,
		.counter = str,
		.token_list = NULL,
		.error_code = 0
	};
	return (lexer);
}

t_token	*ft_create_token(t_type type, t_lexer *lexer)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
	{
		error_msg(lexer, "Creating token: Memory allocation failed");
		return (NULL);
	}
	token->type = type;
	token->value = lexer->start;
	if (type == TOKEN_WORD || type == TOKEN_EOF)
		token->len = lexer->counter - lexer->start;
	else if (type == TOKEN_DQUOTE || type == TOKEN_QUOTE)
	{
		token->value++;
		token->len = lexer->counter - lexer->start - 1;
	}
	else if (type == TOKEN_DLESS || type == TOKEN_DGREATER)
		token->len = 2;
	else
		token->len = 1;
	return (token);
}

t_lexer	ft_lexer(char *str)
{
	t_lexer	lexer;

	lexer = (t_lexer){};
	// if (ft_strlen(str) == 0)
	// {
	// 	lexer.error_code = -1;
	// 	return (lexer);
	// }
	lexer = ft_init_lexer(str);
	if (ft_find_token(&lexer) == FALSE)
	{
		lexer.error_code = -1;
		return (lexer);
	}
	set_lexer_root(lexer.token_list);
	return (lexer);
}
