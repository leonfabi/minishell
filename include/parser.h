#ifndef PARSER_H
# define PARSER_H

// int execve(const char *filename, char *const argv[], char *const envp[])

typedef enum e_parscmd
{
	EXECUTE,
	PIPE,
	REDIR,
	COMMAND
}	t_parscmd;

typedef struct cmd	t_cmd;

struct cmd
{
	int		type;
};

typedef struct execcmd
{
	int		type;
	char	*bin; // echo -> builtin -> Aufruf von builtin
	char	**argv; // echo; -n; hasdf; sadfasdf;
	char	**envp; // environments
}	t_execcmd;

typedef struct redircmd
{
	int		type;
	t_cmd	*cmd; // check what cmd pointer is
	t_cmd	*next;
	char	*file; // word token after redirect ft_strndup(token, token_len)
	int		mode; // depends on the token before file e.g. dgreater = append
	int		fd;
}	t_redircmd;

typedef struct pipecmd
{
	int			type;
	t_cmd	*left;
	t_cmd	*right;
}	t_pipecmd;

typedef struct command
{
	int			type;
	t_cmd	*exec;
	t_cmd	*red;
}	t_command;


t_cmd	*ft_parser(t_lexer *lexer);

#endif
