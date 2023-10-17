#ifndef UTILS_H
# define UTILS_H

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
 * Cleanup function for the heredoc child. Environment and path
 * variables are being retrieved by getters..
 * `<PARAM>`:
 * Nothing;
 * `<RETURN>`:
 * Nothing */
void	here_cleanup(void);

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
 * Getter for the environment array of strings.
 * `<RETURN>`:
 * Pointer to array of strings containing the environment variables */
char	***get_env_arr(void);

/* `<SUMMARY>`:
 * Setter function for setting the pointer to the environment array.
 * `<PARAM>`:
 * `env`: array of strings holding the environment variables;
 * `<RETURN>`:
 * Nothing */
void	set_env_arr(char **env);

/* `<SUMMARY>`:
 * Getter for the bin_path array of strings.
 * `<RETURN>`:
 * Pointer to array of strings containing the bin_path */
char	***get_bin_path(void);

/* `<SUMMARY>`:
 * Setter function for setting the pointer to the bin_path array.
 * `<PARAM>`:
 * `bin`: array of strings holding the bin_path;
 * `<RETURN>`:
 * Nothing */
void	set_bin_path(char **bin);

/* `<SUMMARY>`:
 * Printer for error message that prints up to 3 strings into its message.
 * Always adds "minishell: " to the front of the error message.
 * `<PARAM>`:
 * `s1`: first error message string;
 * `s2`: second error message string;
 * `s3`: third error message string;
 * `<RETURN>`:
 * Nothing */
void	general_error(char *s1, char *s2, char *s3);

/* `<SUMMARY>`:
 * Printer for parser error message that prints the wrong token type.
 * `<PARAM>`:
 * `type`: type of token after the redirect;
 * `<RETURN>`:
 * Nothing */
void	parse_error(t_type type);

/* `<SUMMARY>`:
 * Function to free the string and additionally sets it to `NULL`..
 * `<PARAM>`:
 * `to_free`: string to free;
 * `<RETURN>`:
 * Nothing */
void	adv_free(char **to_free);

/* `<SUMMARY>`:
 * Function that prints out an error if forking failed.
 * `<PARAM>`:
 * none;
 * `<RETURN>`:
 * `pid of the forked process or 0 if in child process` */
pid_t	adv_fork(void);

#endif
