#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/header/libft.h"
# include "defines.h"
# include "signal_handler.h"
# include "lexer.h"

typedef struct s_main
{
	char		*user;
	t_env		env;
	t_path		bin_path;
	t_bool		no_environment;
	t_lexer		lexer;
	t_termios	xterm;
}	t_main;

#endif