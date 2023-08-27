#include "minishell.h"
#include "builtins.h"

// main loop
// signal_handler
// readline
// lexer
// parser -> expander
// executer
// readline

int	main(int argc, char *argv[], char *envp[])
{
	t_main		main;

	main = (t_main){};
	init_shell(&main, envp);
	print(STDOUT_FILENO, "HELLO");
	// while (TRUE)
		// mainloop
	return (EXIT_SUCCESS);
}
