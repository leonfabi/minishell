#ifndef PARSER_H
# define PARSER_H

# include "defines.h"
# include "lexer.h"

/* `<SUMMARY>`:
 * Main entrance point for the parsing routine, and beginning
 * of the AST representation of our commands.
 * `<PARAM>`:
 * `tok`: double linked list head of our tokens from the tokenizer;
 * `sh`: Main struct holding all the attributes of the shell;
 * `<RETURN>`:
 * Returns the top node of the AST. */
t_cmd	*parse_command(t_dlist **tok, t_main *sh);

// Function for initializing an execute node of the AST
t_cmd	*execcmd(t_main *sh);

// Function for initializing a redirect node of the AST
t_cmd	*redircmd(t_cmd *subcmd, t_token *tok, t_dlist **file, char **env);

// Function for initializing a pipe node of the AST
t_cmd	*pipecmd(t_cmd *left, t_cmd *right);

/* `<SUMMARY>`:
 * Function to determine the correct file descriptor for the
 * redirection node of the AST.
 * `<PARAM>`:
 * `type`: type of the redirect token;
 * `<RETURN>`:
 * File descriptor 1 or 0 for stdout or stdin. */
int		get_correct_fd(t_type type);

/* `<SUMMARY>`:
 * Function to determine the correct file open mode for the
 * redirection node of the AST.
 * `<PARAM>`:
 * `type`: type of the redirect token;
 * `<RETURN>`:
 * Bit masks to get the correct open mode for a file. */
int		get_correct_mode(t_type type);

/* `<SUMMARY>`:
 * Function for adjusting the AST when multiple redirects are set.
 * Changes the order of them if necessary.
 * `<PARAM>`:
 * `subcmd`: command node of a redirection node;
 * `cmd`: command node of a redirection node;
 * `<RETURN>`:
 * Pointer to the corrected command node */
t_cmd	*adjust_redir(t_cmd *subcmd, t_redircmd *cmd);

/* `<SUMMARY>`:
 * Function for getting the token struct out of the linked list.
 * `<PARAM>`:
 * `token`: pointer to current token in the double linked list;
 * `<RETURN>`:
 * Returns the extracted token struct. */
t_token	*get_token(t_dlist *token);

/* `<SUMMARY>`:
 * Function for getting a pointer to the start of the current token value.
 * `<PARAM>`:
 * `token`: pointer to current token in the double linked list;
 * `<RETURN>`:
 * Returns the token value of the current token. */
char	*get_token_value(t_dlist *token);

/* `<SUMMARY>`:
 * Function for getting the token type out of the linked list.
 * `<PARAM>`:
 * `token`: pointer to current token in the double linked list;
 * `<RETURN>`:
 * Returns the token type of the current token. */
t_type	get_token_type(t_dlist *token);

/* `<SUMMARY>`:
 * Function for getting the length of the value from the current token.
 * `<PARAM>`:
 * `token`: pointer to current token in the double linked list;
 * `<RETURN>`:
 * Returns the token length of the current token. */
int		get_token_length(t_dlist *token);

/* `<SUMMARY>`:
 * Helper function to check if the token is a redirect token.
 * `<PARAM>`:
 * `type`: type of the current token;
 * `<RETURN>`:
 * `TRUE` if token is a redirection token, otherwise `FALSE`. */
t_bool	check_redirect(t_type type);

/* `<SUMMARY>`:
 * Helper function to check if the token is either of type
 * 'TOKEN_WORD', 'TOKEN_DQUOTE', or 'TOKEN_QUOTE' to handle 
 * them accordingly.
 * `<PARAM>`:
 * `type`: type of the current token;
 * `<RETURN>`:
 * `TRUE` if token is WORD, QUOTE, or DQUOTE token, otherwise `FALSE`. */
t_bool	check_arguments(t_type type);

/* `<SUMMARY>`:
 * Helper function to check for 'TOKEN_PIPE' tokens.
 * `<PARAM>`:
 * `type`: type of the current token;
 * `<RETURN>`:
 * `TRUE` if token is pipe token, otherwise `FALSE`. */
t_bool	check_metachars(t_type type);

/* `<SUMMARY>`:
 * Helper function to get the correct redirection for the
 * redirection node of the AST.
 * `<PARAM>`:
 * `subcmd`: command that is getting attached to the redir command;
 * `list`: double linked list of the tokens;
 * `env`: environment array of strings;
 * `<RETURN>`:
 * Either the selected redirect node or NULL if failure. */
t_cmd	*select_redirect(t_cmd *subcmd, t_dlist **list, char **env);

/* `<SUMMARY>`:
 * Helper function to check if the current token needs to be
 * connected to the following token.
 * `<PARAM>`:
 * `tok`: token to be checked;
 * `<RETURN>`:
 * `TRUE` if token needs to be connected, otherwise `FALSE`. */
t_bool	check_tok_connection(t_token *tok);

/* `<SUMMARY>`:
 * Entry function for connecting tokens not divided by whitespaces.
 * `<PARAM>`:
 * `list`: double linked list of the tokens;
 * `env`: environment array of strings;
 * `<RETURN>`:
 * The connected and expanded string from the tokens. If it does not
 * need to connect or expand anything, it will just return the given
 * token value. */
char	*connect_tokens(t_dlist **list, char **env);

/* `<SUMMARY>`:
 * Cleanup function for the AST.
 * `<PARAM>`:
 * `cmd`: Head root of the abstract syntax tree;
 * `<RETURN>`:
 * Nothing */
void	clean_ast(t_cmd *cmd);

#endif
