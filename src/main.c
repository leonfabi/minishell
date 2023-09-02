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

void	ft_print_ast(t_cmd *cmd, char *str);

void	ft_print_pipe_node(t_cmd *cmd, char *str)
{
	t_pipecmd	*tmp;

	tmp = NULL;
	printf("Node type: %s\n", parse_types[cmd->type]);
	tmp = (t_pipecmd *)cmd;
	if (tmp->left != NULL)
		printf("Left points to: %s\n", parse_types[tmp->left->type]);
	else
		printf("Left points to NULL\n");
	if (tmp->right != NULL)
		printf("Right points to: %s\n", parse_types[tmp->right->type]);
	else
		printf("Right points to NULL\n");
	ft_print_ast(tmp->left, "LEFT");
	ft_print_ast(tmp->right, "RIGHT");
}

void	ft_print_exec_node(t_cmd *cmd, char *str)
{

}

void	ft_print_ast(t_cmd *cmd, char *str)
{
	printf("Node type: %s\n", parse_types[cmd->type]);
	if (cmd != NULL)
	{
		printf("%s\t", str);
		if (cmd->type == PIPE)
			ft_print_pipe_node(cmd, str);
		if (cmd->type == EXECUTE)
			ft_print_exec_node(cmd, str);
	}
	return ;
}

void	print_AST(t_cmd *cmd)
{
	t_execcmd	*ecmd;
	t_pipecmd	*pcmd;
	t_redircmd	*rcmd;
	int			i;

	i = -1;
	if (cmd == NULL)
		return ;
	switch (cmd->type)
	{
		default:
			return ;
		case EXECUTE:
			ecmd = (t_execcmd *)cmd;
			while (ecmd->argv[++i] != NULL)
			{
				if (i == 0)
					printf("%s: %s ", parse_types[ecmd->type], ecmd->argv[i]);
				else
					printf("%s ", ecmd->argv[i]);
			}
			printf("\n---------------------------------------------------\n");
			break ;
		case REDIR:
			rcmd = (t_redircmd *)cmd;
			printf("%s: %s\n", parse_types[rcmd->type], rcmd->file);
			print_AST(rcmd->cmd);
			break ;
		case PIPE:
			pcmd = (t_pipecmd *)cmd;
			printf("%s: %s\n", parse_types[pcmd->type], "Node");
			printf("---------------------------------------------------\n");
			print_AST(pcmd->left);
			print_AST(pcmd->right);
			break ;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int			len;
	t_main		main;
	char		*str;

	main = (t_main){};
	init_shell(&main, envp);
	// main.lexer = ft_lexer("cat < test.txt | grep hello | wc > out.log");
	str = readline(" > ");
	len = ft_strlen(str);
	main.lexer = ft_lexer(str);
	// main.lexer = ft_lexer("'test' < \"test\" | 'hello'");
	ft_print_token_list(&main.lexer);
	// main.cmd = ft_parser(&main.lexer);
	main.cmd = parse_command(&main.lexer.token_list, main.env);
	printf("Input: ");
	for(int i = 0; i <= len; i++) {
		if (str[i] == '\0') {
			printf("\\0"); // print \0 for null character
		} else {
			printf("%c", str[i]);
		}
	}
	printf("\n");
	print_AST(main.cmd);
	clean_ast(main.cmd);
	ft_dlstclear(&main.lexer.token_list, &free);
	ft_arrfree(main.env);
	free(str);
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
