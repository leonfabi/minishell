#ifndef EXECUTOR_H
# define EXECUTOR_H

/* `<SUMMARY>`:
 * Main entrance point for the execution routine. Creates a context
 * variable which holds information about the current file descriptors
 * which help with routing the inputs and outputs accordingly.
 * `<PARAM>`:
 * `ast`: root node of the AST;
 * `<RETURN>`:
 * Returns QUIT if the program should quit because of the ft_exit
 * builtin or NO_QUIT if not. */
t_quit	executor_main(t_cmd *ast);

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
 * `exec`: current execution node of the AST;
 * `ctx`: context for handling the correct redirection; */
void	execute_command(t_execcmd *exec, t_context *ctx);

/* `<SUMMARY>`:
 * Function to execute the implemented builtin functions.
 * `<PARAM>`:
 * `exec`: current execution node of the AST;
 * `ctx`: context for handling the correct redirection;
 * `<RETURN>`:
 * Returns TRUE if it is a builtin and FALSE otherwise. */
t_bool	execute_builtin(t_execcmd *exec, t_context *ctx);

/* `<SUMMARY>`:
 * Function to execute a redirection. dups the correct file descriptors
 * and also calls the heredoc function if needed.
 * `<PARAM>`:
 * `redir`: current redirection node of the AST;
 * `ctx`: context for handling the correct redirection; */
void	execute_redir(t_redircmd *redir, t_context *ctx);

/* `<SUMMARY>`:
 * Function to execute a node. Furthermore, decides if it is going
 * to be a builtin function or another function.
 * `<PARAM>`:
 * `pcmd`: current pipe node of the AST;
 * `ctx`: context for handling the correct redirection; */
void	execute_pipe(t_pipecmd *pcmd, t_context *ctx);

/* `<SUMMARY>`:
 * copy_context copies the necessary variables during the
 * execution of the AST from the left and right side of the
 * pipe. Furthermore, it appends the newly created PIDs to
 * the array.
 * `<PARAM>`:
 * `ast`: current node of the AST;
 * `ctx`: context for handling the correct redirection;
 * `<RETURN>`:
 * Returns TRUE if it is a builtin and FALSE otherwise. */
void	copy_context(t_context *ctx, t_context next_ctx);

/* `<SUMMARY>`:
 * Function to add the pid created by the `fork()` call
 * to the array of pids in the current context.
 * `<PARAM>`:
 * `pid`: child pid to add to the array of pids;
 * `ctx`: context for handling the correct redirection; */
void	add_child_pids(pid_t pid, t_context *ctx);

/* `<SUMMARY>`:
 * Function to wait for all pids stored in the pid array
 * in the context and to set the exit code accordingly.
 * `<PARAM>`:
 * `ctx`: context for handling the correct redirection; */
void	child_reaper(t_context *ctx);

/* `<SUMMARY>`:
 * Function to execute the heredoc function. Dups the correct
 * file descriptors and creates a child for the heredoc input.
 * `<PARAM>`:
 * `redir`: current redirection node of the AST;
 * `ctx`: context for handling the correct redirection; */
void	execute_heredoc(t_redircmd *redir, t_context *ctx);

int		*get_close_fd(void);

void	set_close_fd(int set_fd);

#endif
