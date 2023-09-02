#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

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

typedef struct execcmd
{
	t_parscmd	type;
	char		*argv[15];
}	t_execcmd;

typedef struct redircmd
{
	t_parscmd	type;
	t_cmd		*cmd;
	char		*file;
	int			mode;
	int			fd;
}	t_redircmd;

typedef struct pipecmd
{
	t_parscmd	type;
	t_cmd	*left;
	t_cmd	*right;
}	t_pipecmd;


t_cmd	*ft_parser(t_lexer *lexer);

t_token	*get_token(t_dlist *token);

t_bool	nulterminate(t_dlist **token);

t_cmd *execcmd(void);

t_cmd *redircmd(t_cmd *subcmd, t_token *tok, int mode, int fd);

t_cmd *pipecmd(t_cmd *left, t_cmd *right);

t_type	get_token_type(t_dlist *token);

t_cmd	*parse_command(t_dlist **token, char **env);

char	*expand_token(t_token *tok, char **env);

void	clean_ast(t_cmd *cmd);

char	*expand_token(t_token *tok, char **env);

#endif
