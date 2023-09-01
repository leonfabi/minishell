#include "minishell.h"
// int	ft_check_quotes(char *str)
// {
// 	int	count;
// 	int	quote_double;
// 	int	quote_single;

// 	count = -1;
// 	quote_double = 0;
// 	quote_single = 0;
// 	while (str[++count] != '\0')
// 	{
// 		if (str[count] == 34)
// 			quote_double++;
// 		else if (str[count] == 39)
// 			quote_single++;
// 	}
// 	if (quote_double % 2 == 0 && quote_single % 2 == 0)
// 		return (0);
// 	return (1);
// }

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
		token->value_length = lexer->counter - lexer->start;
	else if (type == TOKEN_DQUOTE || type == TOKEN_QUOTE)
	{
		token->value++;
		token->value_length = lexer->counter - lexer->start - 1;
	}
	else if (type == TOKEN_DLESS || type == TOKEN_DGREATER)
		token->value_length = 2;
	else
		token->value_length = 1;
	return (token);
}

t_lexer	ft_lexer(char *str)
{
	t_lexer	lexer;

	lexer = (t_lexer){};
	lexer = ft_init_lexer(str);
	if (ft_find_token(&lexer) == FALSE)
		return (lexer.error_code--, lexer);
	return (lexer);
}
