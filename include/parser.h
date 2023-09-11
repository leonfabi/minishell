#ifndef PARSER_H
# define PARSER_H

# include "defines.h"
# include "lexer.h"
# include <fcntl.h>

/* `<SUMMARY>`:
 Main entrance point for the parsing routine, and beginning
 of the AST representation of our commands.
 `<PARAM>`:
 `tok`: double linked list head of our tokens from the tokenizer;
 `sh`: Main struct holding all the attributes of the shell;
 `<RETURN>`:
 Returns the top node of the AST. */
t_cmd	*parse_command(t_dlist **tok, t_main *sh);

// Function for initializing an execute node of the AST
t_cmd	*execcmd(t_main *sh);

// Function for initializing a redirect node of the AST
t_cmd	*redircmd(t_cmd *subcmd, t_token *tok, t_dlist **file, char **env);

// Function for initializing a pipe node of the AST
t_cmd	*pipecmd(t_cmd *left, t_cmd *right);

/* `<SUMMARY>`:
 Function for getting the token struct out of the linked list.
 `<PARAM>`:
 `token`: pointer to current token in the double linked list;
 `<RETURN>`:
 Returns the extracted token struct. */
t_token	*get_token(t_dlist *token);

/* `<SUMMARY>`:
 Function for getting the token type out of the linked list.
 `<PARAM>`:
 `token`: pointer to current token in the double linked list;
 `<RETURN>`:
 Returns the token type of the current token. */
t_type	get_token_type(t_dlist *token);

/* `<SUMMARY>`:
 Function for getting the length of the value from the current token.
 `<PARAM>`:
 `token`: pointer to current token in the double linked list;
 `<RETURN>`:
 Returns the token length of the current token. */
int		get_token_length(t_dlist *token);

/* `<SUMMARY>`:
 Function for getting a pointer to the start of the current token value.
 `<PARAM>`:
 `token`: pointer to current token in the double linked list;
 `<RETURN>`:
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
t_cmd	*select_redirect(t_cmd *subcmd, t_dlist **list, char **env);

// Util function to nulterminate the strings on the readline string.
t_bool	correct_token(t_type type);

char	*connect_tokens(t_dlist **list, char **env);

t_bool	check_tok_connection(t_token *tok);

// WARNING: CHECK IF WE NEED THIS FUNCTION ANYMORE???????
// Function to nulterminate the readline string
t_bool	nulterminate(t_dlist **token);

// FIX: add cleaning the allocated strings for redir and exec nodes
void	clean_ast(t_cmd *cmd);

char	*expand_token(t_token *tok, char **env);

char	*advance_and_copy(char **input, int size);

char	*expand_special(char *input);

t_list	*create_keylist(char *input);

#endif
