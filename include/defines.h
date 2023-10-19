/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:04 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/19 11:48:05 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// Standard Library Function Headers
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// System Calls and OS-specific interfaces
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

// Used for interactive input editing and history
# include <readline/history.h>
# include <readline/readline.h>

# define TRUE 1
# define FALSE 0
# define MAXARGS 20
# define O_HEREDOC 04000
# define CHILD_FORK 0
# define MAX_CHILDS 1024
# define GENERAL_ERROR 1

typedef enum e_quit
{
	QUIT = 1 << 0,
	NO_QUIT = 1 << 1
}	t_quit;

// Define error strings
# define ERR_ARG "too many arguments"
# define ERR_PARS "Expected a string, but found "
# define ERR_ID "not a valid identifier"
# define ERR_CMD "command not found"

/* `<summary>`:
 Typedefs to use a shorter version in the code
 for more readability and structure.
 ans also forward declaration for usage in the prototypes.*/
typedef struct sigaction	t_signal;
typedef struct termios		t_termios;
typedef void				t_handler(int);
typedef struct s_cmd		t_cmd;
typedef struct s_execcmd	t_execcmd;
typedef struct s_pipecmd	t_pipecmd;
typedef struct s_redircmd	t_redircmd;
typedef int					(*t_builtin_p)(t_execcmd *);

// Represents either `TRUE` (1) or `FALSE` (0).
typedef int					t_bool;

// Forward declaration of the s_dlist struct for the lexer.
typedef struct s_dlist		t_dlist;

struct s_dlist
{
	void		*content;
	t_dlist		*next;
	t_dlist		*prev;
};

typedef struct s_lexer
{
	char	*start;
	char	*counter;
	t_dlist	*token_list;
	int		error_code;
}	t_lexer;

/* `<SUMMARY>`:
 * Main struct of the shell for holding all its attributes.
 * `<MEMBER>`
 * char			`*user`;
 * char			`**env`;
 * char			`**bin_path`;
 * t_lexer		`lexer`;
 * t_termios	`xterm`;
 * int			`stdin`;
 * int			`stdout`;
 * int			`stderr`;
 * int			`pars_error`;
 */
typedef struct s_main
{
	char		*user;
	char		**env;
	char		**bin_path;
	t_lexer		lexer;
	t_termios	xterm;
	int			stdin;
	int			stdout;
	int			stderr;
	int			pars_error;
}	t_main;

typedef enum e_parscmd
{
	EXECUTE = 1 << 0,
	PIPE = 1 << 1,
	REDIR = 1 << 2
}	t_parscmd;

struct s_cmd
{
	int		type;
};

struct s_execcmd
{
	t_parscmd	type;
	char		*bin;
	char		*argv[MAXARGS];
	t_main		*sh;
};

struct s_redircmd
{
	t_parscmd	type;
	t_cmd		*cmd;
	char		*file;
	int			mode;
	int			fd;
	t_bool		expand;
};

struct s_pipecmd
{
	t_parscmd	type;
	t_cmd		*left;
	t_cmd		*right;
};

typedef enum e_type
{
	TOKEN_WORD = 1 << 0,
	TOKEN_PIPE = 1 << 1,
	TOKEN_LESS = 1 << 2,
	TOKEN_GREATER = 1 << 3,
	TOKEN_DLESS = 1 << 4,
	TOKEN_DGREATER = 1 << 5,
	TOKEN_EOF = 1 << 6,
	TOKEN_QUOTE = 1 << 7,
	TOKEN_DQUOTE = 1 << 8,
	TOKEN_NEWLINE = 1 << 9
}	t_type;

typedef struct s_token
{
	t_type	type;
	char	*value;
	int		len;
}	t_token;

typedef struct s_context {
	int		fd[2];
	int		fd_close;
	int		exit_code;
	pid_t	pids[MAX_CHILDS];
	int		child;
	t_bool	error;
	t_bool	quit;
	t_bool	pipeline;
}	t_context;

#endif
