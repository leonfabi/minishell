#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include "defines.h"
# include "environment.h"
# include "libft.h"
# include "signal_handler.h"
# include "lexer.h"
# include "builtins.h"
# include "parser.h"

typedef struct s_main
{
	char		*user;
	char		**env;
	char		**bin_path;
	t_bool		no_environment;
	t_lexer		lexer;
	struct cmd	*cmd;
	t_termios	xterm;
	int			stdin;
	int			stdout;
	int			stderr;
}	t_main;

void	adv_free(char **to_free);

#endif
