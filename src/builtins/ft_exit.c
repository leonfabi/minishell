#include "minishell.h"

int	ft_exit(t_execcmd *cmd)
{
	int		exit_code;

	set_exit_status(ft_atoi(cmd->argv[1]));
	exit_code = *get_exit_status();
	// cmd = exit;

	// cmd == "exit" => TRUE
	// => exit routine (free all, cleanup + exit);

	// exit(0);

	// Send SIGINT signal
	// FIX: create a cleaupt at exit routine
	clean_ast(cmd->sh->ast_root);
	exit(exit_code);
}
