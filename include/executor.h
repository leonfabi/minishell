#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "defines.h"

/* `<SUMMARY>`:
 * Main entrance point for the execution routine. Creates a context
 * variable which holds information about the current file descriptors
 * which help with routing the inputs and outputs accordingly.
 * `<PARAM>`:
 * `ast`: root node of the AST;
 * `<RETURN>`:
 * Returns TRUE if the builtin exit function is being called. */
t_bool	executor_main(t_cmd *ast);

/* `<SUMMARY>`:
 * Function to examine the type of the current node being processed
 * of the AST and calling the appropriate function.
 * `<PARAM>`:
 * `ast`: current node of the AST;
 * `ctx`: context for handling the correct redirection; */
void	exec_node(t_cmd *ast, t_context *ctx);

/* `<SUMMARY>`:
 * Function to execute a node. Furthermore, decides if it is going
 * to be a builtin function or another function.
 * `<PARAM>`:
 * `ast`: current node of the AST;
 * `ctx`: context for handling the correct redirection; */
void	execute_command(t_execcmd *exec, t_context *ctx);

/* `<SUMMARY>`:
 * Function to execute the implemented builtin functions.
 * `<PARAM>`:
 * `ast`: current node of the AST;
 * `ctx`: context for handling the correct redirection;
 * `<RETURN>`:
 * Returns TRUE if it is a builtin and FALSE otherwise. */
t_bool	execute_builtin(t_execcmd *exec, t_context *ctx);

#endif
