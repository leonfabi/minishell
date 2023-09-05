#include "minishell.h"

void	error_handler(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	ft_dlstclear(&(lexer->token_list), &free);
}

void	error_msg(t_lexer *lexer, char *str)
{
	printf("Error: %s\n", str);
	error_handler(lexer);
}
