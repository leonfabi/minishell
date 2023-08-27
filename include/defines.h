#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0

/*
 `<summary>`:
 Represents an array of strings containing paths.
*/
typedef char**			t_path;
/*
 `<summary>`:
 Represents either TRUE (1) or FALSE (0).
*/
typedef int				t_bool;
/*
 `<summary>`:
 Predefine the main struct to use t_main in the struct definition.
 '<struct member>':
	char		*user;
	t_env		*env;
	t_path		bin_path;
	t_bool		no_environment;
	t_lexer		lexer;
	t_termios	xterm;
	int			stdin;
	int			stdout;
	int			stderr;
*/
typedef struct s_main	t_main;

#endif
