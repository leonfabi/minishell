#ifndef PARSER_H
# define PARSER_H

// int execve(const char *filename, char *const argv[], char *const envp[])

typedef enum e_parscmd
{
	EXECUTE,
	PIPE,
	REDIR
}	t_parscmd;

typedef struct cmd	t_cmd;

struct cmd
{
	int		type;
};

// echo -n hello world test 

typedef struct execcmd
{
	int		type;
	char	*bin; // echo
	char	**argv; // echo; -n; hello; world; test -> array of strings
	char	**envp; // environments -> übergeben von 
}	t_execcmd;

typedef struct redircmd
{
	int		type;
	t_cmd	*cmd;
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


t_cmd	*ft_parser(t_lexer *lexer);

#endif
