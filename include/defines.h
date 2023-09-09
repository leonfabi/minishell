#ifndef DEFINES_H
# define DEFINES_H

# include <termios.h>

# define TRUE 1
# define FALSE 0
# define WHITESPACE " \t\r\n\v"
# define MAXARGS 20
# define O_HEREDOC 0x0300

typedef struct s_dlist	t_dlist;

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
typedef struct cmd	t_cmd;

/* `<summary>`:
 Represents either TRUE (1) or FALSE (0). */
typedef int				t_bool;


typedef enum e_parscmd
{
	EXECUTE,
	PIPE,
	REDIR
}	t_parscmd;

struct cmd
{
	int		type;
};

typedef struct execcmd
{
	t_parscmd	type;
	char		*bin;
	char		*argv[MAXARGS];
	t_main		*sh;
}	t_execcmd;

typedef struct redircmd
{
	t_parscmd	type;
	t_cmd		*cmd;
	char		*file;
	int			mode;
	int			fd;
	t_bool		expand;
}	t_redircmd;

typedef struct pipecmd
{
	t_parscmd	type;
	t_cmd	*left;
	t_cmd	*right;
}	t_pipecmd;


typedef enum e_type
{
	TOKEN_WORD,
	TOKEN_FLAG,
	TOKEN_PIPE,
	TOKEN_LESS,
	TOKEN_GREATER,
	TOKEN_DLESS,
	TOKEN_DGREATER,
	TOKEN_EOF,
	TOKEN_QUOTE,
	TOKEN_DQUOTE,
	TOKEN_NEWLINE
}	t_type;

typedef struct s_dlist
{
	void	*content;
	t_dlist	*next;
	t_dlist	*prev;
}	t_dlist;

typedef struct s_token
{
	t_type	type;
	char	*value;
	int		len;
}	t_token;

typedef struct s_lexer
{
	char	*start;
	char	*counter;
	t_dlist	*token_list;
	int		error_code;
}	t_lexer;

/* `<summary>`:
 Define structs to use a shorter version in the code
 for more readability and structure. */
typedef struct sigaction	t_signal;
typedef struct termios		t_termios;
typedef void				t_handler(int);

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
}	t_main;

#endif
