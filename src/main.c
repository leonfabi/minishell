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

char* parse_types[] = {
	"EXECUTE",
	"PIPE",
	"REDIR"
};

void	ft_print_token_list(t_lexer *lexer)
{
	int		len;
	int		count;
	t_type	type;
	t_dlist	*tmp;

	len = 0;
	tmp = lexer->token_list;
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
	lexer->token_list = tmp;
}

void	ft_print_ast(t_cmd *cmd, char *str)
{
	t_pipecmd	*tmp;

	tmp = NULL;
	if (cmd != NULL)
	{
		printf("%s\n", str);
		printf("Node type: %s\n", parse_types[cmd->type]);
		if (cmd->type == PIPE)
		{
			tmp = (t_pipecmd *)cmd;
			ft_print_ast(tmp->left, "LEFT");
			ft_print_ast(tmp->right, "RIGHT");
		}
	}
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_main		main;

	main = (t_main){};
	init_shell(&main, envp);
	// main.lexer = ft_lexer("cat < test.txt | grep hello | wc > out.log");
	// main.lexer = ft_lexer("cat");
	main.lexer = ft_lexer("'test' < \"test\" | 'hello'");
	ft_print_token_list(&main.lexer);
	// main.cmd = ft_parser(&main.lexer);
	// ft_print_ast(main.cmd, "START");
	// ft_arrprint((const char **)main.env);
	// printf("%lu\n\n", ft_arrlen((const char **)main.env));
	// env(main.env);
	// ft_unset(main.env, "USER");
	// env(main.env);
	// // printf("%lu\n\n", ft_arrlen((const char **)main.env));
	// // ft_arrprint((const char **)main.env);
	// ft_arrfree(main.bin_path);
	// ft_arrfree(main.env);

	return (EXIT_SUCCESS);
}
