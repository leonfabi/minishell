#include "minishell.h"

int	exit(char **args)
{
	cmd = exit;

	cmd == "exit" => TRUE
	=> exit routine (free all, cleanup + exit);

	exit(0);

	// Send SIGINT signal
}
