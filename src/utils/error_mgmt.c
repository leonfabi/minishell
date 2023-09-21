#include "libft.h"
#include "lexer.h"
#include "signals.h"

void	error_handler(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	ft_dlstclear(&(lexer->token_list), &free);
}

void	error_msg(t_lexer *lexer, char *str)
{
	ft_fprintf(2, "minishell: lexer: %s\n", str);
	set_exit_status(GENERAL_ERROR);
	error_handler(lexer);
}

void	general_error(char *s1, char *s2, char *s3)
{
	if (NULL == s3 && NULL == s2)
	{
		ft_fprintf(STDERR_FILENO, "minishell: %s\n", s1);
	}
	else if (NULL == s3)
	{
		ft_fprintf(STDERR_FILENO, "minishell: %s: %s\n", s1, s2);
	}
	else
	{
		ft_fprintf(STDERR_FILENO, "minishell: %s: %s: %s\n", s1, s2, s3);
	}
}

void	parse_error(t_type type)
{
	ft_fprintf(2, "minishell: %s", ERR_PARS);
	if (type & (TOKEN_LESS | TOKEN_GREATER | TOKEN_DLESS | TOKEN_DGREATER))
		ft_fprintf(2, "a redirection\n");
	else if (type & TOKEN_EOF)
		ft_fprintf(2, "end of the input\n");
	else if (type & TOKEN_PIPE)
		ft_fprintf(2, "a pipe\n");
}
