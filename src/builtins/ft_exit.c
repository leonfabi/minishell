#include "minishell.h"

int	ft_exit(t_execcmd *cmd)
{
	// cmd = exit;

	// cmd == "exit" => TRUE
	// => exit routine (free all, cleanup + exit);

	// exit(0);

	// Send SIGINT signal
	return (TRUE);
}
