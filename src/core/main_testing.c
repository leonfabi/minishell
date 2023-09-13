#include "minishell.h"

#include <math.h>

char* types[] = {
	"TOKEN_WORD",
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

const char *get_token_name(t_type tok)
{
	int		index;

	index = log2(tok);
	return (types[index]);
}

char* parse_types[] = {
	"EXECUTE",
	"PIPE",
	"REDIR"
};

const char *get_node_name(t_parscmd type)
{
	int		index;

	index = log2(type);
	return (parse_types[index]);
}
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
		len = ((t_token *)lexer->token_list->content)->len;
		printf("TOKEN: %s\t", get_token_name(type));
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
					printf("%s: %s ", get_node_name(ecmd->type), ecmd->argv[i]);
				else
					printf("%s ", ecmd->argv[i]);
			}
			printf("\n---------------------------------------------------\n");
			break ;
		case REDIR:
			rcmd = (t_redircmd *)cmd;
			printf("%s: %s\n", get_node_name(ecmd->type), rcmd->file);
			// printf("Cmd: %s, fd: %d, mode: %d\n", parse_types[rcmd->cmd->type], rcmd->fd, rcmd->mode);
			print_AST(rcmd->cmd);
			break ;
		case PIPE:
			pcmd = (t_pipecmd *)cmd;
			printf("%s: %s\n", get_node_name(ecmd->type), "Node");
			printf("---------------------------------------------------\n");
			print_AST(pcmd->left);
			print_AST(pcmd->right);
			break ;
	}
}

// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_main	sh;
// 	t_cmd	*ast;
// 	char	*str;
// 
// 	sh = (t_main){};
// 	ast = NULL;
// 	str = NULL;
// 	init_shell(&sh, envp);
// 	str = readline(" > ");
// 	sh.lexer = ft_lexer(str);
// 	ast = parse_command(&sh.lexer.token_list, &sh);
// 	sh.ast_root = ast;
// 	print_AST(ast);
// }

int	main(int argc, char *argv[], char *envp[])
{
	int			len;
	t_main		sh;
	char		*str;
	t_cmd	*ast;

	sh = (t_main){};
	set_exit_status(EXIT_SUCCESS);
	init_shell(&sh, envp);
	// main.lexer = ft_lexer("cat < test.txt | grep hello | wc > out.log");
	str = readline(" > ");
	len = ft_strlen(str);
	sh.lexer = ft_lexer(str);
	// main.lexer = ft_lexer("'test' < \"test\" | 'hello'");
	ft_print_token_list(&sh.lexer);
	// main.cmd = ft_parser(&main.lexer);
	ast = parse_command(&sh.lexer.token_list, &sh);
	// printf("Input: ");
	// for(int i = 0; i <= len; i++) {
	// 	if (str[i] == '\0') {
	// 		printf("\\0"); // print \0 for null character
	// 	} else {
	// 		printf("%c", str[i]);
	// 	}
	// }
	// printf("\n");
	print_AST(ast);
	executor(ast);
	// // CLEANUP
	clean_ast(ast);
	if (sh.lexer.error_code != -1)
		ft_dlstclear(&sh.lexer.token_list, &free);
	ft_arrfree(sh.env);
	ft_arrfree(sh.bin_path);
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
