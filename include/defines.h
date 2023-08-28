#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0

/* `<summary>`:
 Represents either TRUE (1) or FALSE (0). */
typedef int				t_bool;

/* `<summary>`:
 Predefine the main struct to use t_main in the struct definition.
 '<struct member>':
	char		*user;
	char		**env;
	char		**bin_path;
	t_bool		no_environment;
	t_lexer		lexer;
	t_termios	xterm;
	int			stdin;
	int			stdout;
	int			stderr; */
typedef struct s_main	t_main;

#endif
