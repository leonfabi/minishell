#include "minishell.h"

/* `<SUMMARY>`:
 * Function to execute the builtin command within a child because it
 * is part of a pipe.
 * `<PARAM>`:
 * `exec`: execution node of the AST;
 * `builtin`: function pointer to the correct builtin function;
 * `ctx`: context for handling the correct redirection;*/
static void	fork_builtin(t_execcmd *exec, t_builtin_p builtin, t_context *ctx)
{
	pid_t	pid;

	pid = adv_fork();
	if (CHILD_FORK == pid)
	{
		dup2(ctx->fd[STDOUT_FILENO], STDOUT_FILENO);
		dup2(ctx->fd[STDIN_FILENO], STDIN_FILENO);
		if (ctx->fd_close >= 0)
			close(ctx->fd_close);
		ctx->exit_code = builtin(exec);
		msh_cleanup(exec->sh);
		close(ctx->fd[STDIN_FILENO]);
		close(ctx->fd[STDOUT_FILENO]);
		exit(ctx->exit_code);
	}
	if (ctx->fd[STDIN_FILENO] != STDIN_FILENO)
		close(ctx->fd[STDIN_FILENO]);
	if (ctx->fd[STDOUT_FILENO] != STDOUT_FILENO)
		close(ctx->fd[STDOUT_FILENO]);
	set_child_pid(pid);
}

/* `<SUMMARY>`:
 * Function to find the corresponding builtin for exec->argv[0].
 * `<PARAM>`:
 * `exec`: execution node of the AST;
 * `<RETURN>`:
 * Returns the function pointer to the correct builtin or NULL. */
static t_builtin_p	is_builtin(t_execcmd *exec)
{
	int					id;
	static const char			*ft_builtin_name[] = {"cd", "echo", "env",\
		"exit", "export", "pwd", "unset", NULL};
	static const t_builtin_p	ft_builtin_p[] = {&ft_cd, &ft_echo, &ft_env,\
		&ft_exit, &ft_export, &ft_pwd, &ft_unset, NULL};

	id = 0;
	while (NULL != ft_builtin_name[id])
	{
		if (ft_strcmp(exec->argv[0],ft_builtin_name[id]) == 0)
			return (ft_builtin_p[id]);
		id++;
	}
	return (NULL);
}

t_bool	execute_builtin(t_execcmd *exec, t_context *ctx)
{
	t_builtin_p	fn_builtin;
	t_bool		check;

	check = FALSE;
	fn_builtin = is_builtin(exec);
	if (ft_strncmp(exec->argv[0], "exit", 4) == 0)
		ctx->quit = TRUE;
	if (fn_builtin != NULL)
	{
		check = TRUE;
		if (ctx->pipeline == TRUE)
			fork_builtin(exec, fn_builtin, ctx);
		else
			ctx->exit_code = fn_builtin(exec);
	}
	return (check);
}
