#include "libft.h"
#include "defines.h"
#include "environment.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "signals.h"
#include "utils.h"

#define GREEN_PROMPT "\e[m\e[0;32m❯ \e[m"
#define RED_PROMPT "\e[m\e[0;31m❯ \e[m"

static void	reset_stdfd(t_main *sh)
{
		dup2(sh->stdin, STDIN_FILENO);
		dup2(sh->stdout, STDOUT_FILENO);
		dup2(sh->stderr, STDERR_FILENO);
}

static void	msh_loop(t_main *sh)
{
	t_cmd	*ast;
	char	*line;
	t_bool	quit;

	while (TRUE)
	{
		user_signal_listener(&sh->xterm);
		if (*get_exit_status() == 0)
			line = readline(GREEN_PROMPT);
		else
			line = readline(RED_PROMPT);
		if (line == NULL)
			break ;
		if (ft_strlen(line) == 0)
			continue ;
		add_history(line);
		sh->lexer = ft_lexer(line);
		ast = parse_command(&sh->lexer.token_list, sh);
		quit = executor_main(ast);
		free(line);
		line = NULL;
		reset_stdfd(sh);
		if (quit == QUIT)
			break ;
	}
}

static void	clean_exit(t_main *sh)
{
	write(1, "exit\n", 5);
	rl_clear_history();
	msh_cleanup(sh);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_main	sh;

	(void) argv;
	if (argc != 1)
		return (EXIT_FAILURE);
	init_shell(&sh, envp);
	msh_loop(&sh);
	clean_exit(&sh);
	return (*get_exit_status());
}
