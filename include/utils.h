#ifndef UTILS_H
# define UTILS_H

# include "defines.h"

/* `<SUMMARY>`:
 * Cleanup function for the AST.
 * `<PARAM>`:
 * `cmd`: Head root of the abstract syntax tree;
 * `<RETURN>`:
 * Nothing */
void	clean_ast(t_cmd *cmd);

/* `<SUMMARY>`:
 * Cleanup function for the main struct of the minishell.
 * It is used within the childs to clean up if execve fails
 * or at the end before exiting the minishell. It also closes
 * the copied file descriptors to avoid tangling file descriptors.
 * `<PARAM>`:
 * `sh`: Main struct holding all the attributes of the shell;
 * `<RETURN>`:
 * Nothing */
void	msh_cleanup(t_main *sh);

/* `<SUMMARY>`:
 * Getter for the AST root to free the AST from the top after execution.
 * `<RETURN>`:
 * Root node of the abstract syntax tree */
t_cmd	**get_ast_root(void);

/* `<SUMMARY>`:
 * Setter function for setting the root node of the AST.
 * `<PARAM>`:
 * `root`: Root node of the abstract syntax tree;
 * `<RETURN>`:
 * Nothing */
void	set_ast_root(t_cmd *root);

/* `<SUMMARY>`:
 * Getter for the lexer root to free the lexer list
 * after parsing.
 * `<RETURN>`:
 * Root node of the abstract syntax tree */
t_dlist	**get_lexer_root(void);

/* `<SUMMARY>`:
 * Setter function for setting the root node of the lexer.
 * `<PARAM>`:
 * `root`: Root node of the lexer;
 * `<RETURN>`:
 * Nothing */
void	set_lexer_root(t_dlist *root);

/* `<SUMMARY>`:
 * Printer for error message that prints up to 3 strings into its message.
 * `<PARAM>`:
 * `s1`: first error message string;
 * `s2`: second error message string;
 * `s3`: third error message string;
 * `<RETURN>`:
 * Nothing */
void	general_error(char *s1, char *s2, char *s3);

void	adv_free(char **to_free);

pid_t	adv_fork(void);

#endif
