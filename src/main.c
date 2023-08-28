#include "minishell.h"

// main loop
// signal_handler
// readline
// lexer
// parser -> expander
// executer
// readline

char* types[] = {
	"TOKEN_WORD",
	"TOKEN_FLAG",
	"TOKEN_PIPE",
	"TOKEN_LESS",
	"TOKEN_GREATER",
	"TOKEN_DLESS",
	"TOKEN_DGREATER",
	"TOKEN_EOF",
	"TOKEN_QUOTE",
	"TOKEN_DQUOTE",
	"TOKEN_NEWLINE"
};

void	ft_print_token_list(t_lexer *lexer)
{
	int		len;
	int		count;
	t_type	type;

	len = 0;
	while(lexer->token_list != NULL)
	{
		count = 0;
		type = ((t_token *)lexer->token_list->content)->type;
		len = ((t_token *)lexer->token_list->content)->value_length;
		printf("TOKEN: %s\t", types[type]);
		while (len > count)
		{
			printf("%c", ((t_token *)lexer->token_list->content)->value[count]);
			count++;
		}
		printf("\n-----------------------\n");
		lexer->token_list = lexer->token_list->next;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_main		main;

	main = (t_main){};
	init_shell(&main, envp);
	main.lexer = ft_lexer("cat < test.txt | grep 'hello' | wc > out.log");
	ft_print_token_list(&main.lexer);

	return (EXIT_SUCCESS);
}
