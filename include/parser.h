#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include <fcntl.h>

# define MAXARGS 20

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
	char		*argv[MAXARGS];
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

/* `<summary>`:
 Main entrance point for the parsing routine, and beginning
 of the AST representation of our commands.
 `<parameter>`:
 `tok`: double linked list head of our tokens from the tokenizer;
 `env`: array of string of the environment variables for expansion;
 `<returns>`:
 Returns the top node of the AST. */
t_cmd	*parse_command(t_dlist **tok, char **env);

// Function for initializing an execute node of the AST
t_cmd	*execcmd(void);

// Function for initializing a redirect node of the AST
t_cmd	*redircmd(t_cmd *subcmd, t_token *tok, char **env);

// Function for initializing a pipe node of the AST
t_cmd	*pipecmd(t_cmd *left, t_cmd *right);

/* `<summary>`:
 Function for getting the token struct out of the linked list.
 `<parameter>`:
 `token`: pointer to current token in the double linked list;
 `<returns>`:
 Returns the extracted token struct. */
t_token	*get_token(t_dlist *token);

/* `<summary>`:
 Function for getting the token type out of the linked list.
 `<parameter>`:
 `token`: pointer to current token in the double linked list;
 `<returns>`:
 Returns the token type of the current token. */
t_type	get_token_type(t_dlist *token);

/* `<summary>`:
 Function for getting the length of the value from the current token.
 `<parameter>`:
 `token`: pointer to current token in the double linked list;
 `<returns>`:
 Returns the token length of the current token. */
int		get_token_length(t_dlist *token);

/* `<summary>`:
 Function for getting a pointer to the start of the current token value.
 `<parameter>`:
 `token`: pointer to current token in the double linked list;
 `<returns>`:
 Returns the token value of the current token. */
char	*get_token_value(t_dlist *token);

// Helper function to check if the token is a redirect token.
t_bool	check_redirect(t_type type);

// Helper function to check if the token is either of type
// 'TOKEN_WORD', 'TOKEN_DQUOTE', or 'TOKEN_QUOTE' to handle 
// them accordingly.
t_bool	check_arguments(t_type type);

// Helper function to check for 'TOKEN_PIPE' tokens.
t_bool	check_metachars(t_type type);

// Helper function to get the correct redirection for the
// redirection node of the AST.
t_cmd	*select_redirect(t_cmd *subcmd, t_dlist *tok_list, char **env);

// Util function to nulterminate the strings on the readline string.
t_bool	correct_token(t_type type);























t_bool	nulterminate(t_dlist **token);

void	clean_ast(t_cmd *cmd);

char	*expand_token(t_token *tok, char **env);

#endif
