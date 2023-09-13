#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_main	sh;
	t_cmd	*ast;
	char	*line;

	(void) argv;
	if (argc != 1)
		return (EXIT_FAILURE);
	init_shell(&sh, envp);
	while (TRUE)
	{
		user_signal_listener(&sh.xterm);
		line = readline(" ˃ ");
		sh.lexer = ft_lexer(line);
		ast = parse_command(&sh.lexer.token_list, &sh);
		executor(ast);
		clean_ast(ast);
		ft_dlstclear(&sh.lexer.token_list, &free);
		free(line);
		line = NULL;
	}
	ft_arrfree(sh.bin_path);
	ft_arrfree(sh.env);
	free(sh.user);
	return (EXIT_SUCCESS);
}
