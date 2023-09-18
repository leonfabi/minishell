#include "minishell.h"

static void	create_child_process(t_execcmd *exec, t_context *ctx)
{
	int			pid;

	pid = adv_fork();
	if (CHILD_FORK == pid)
	{
		dup2(ctx->fd[STDIN_FILENO], STDIN_FILENO);
		dup2(ctx->fd[STDOUT_FILENO], STDOUT_FILENO);
		if (ctx->fd_close >= 0)
			close(ctx->fd_close);
		execve(exec->bin, exec->argv, exec->sh->env);
		msh_cleanup(exec->sh);
		exit(EXIT_FAILURE);
	}
	if (ctx->fd[STDIN_FILENO] != STDIN_FILENO)
		close(ctx->fd[STDIN_FILENO]);
	if (ctx->fd[STDOUT_FILENO] != STDOUT_FILENO)
		close(ctx->fd[STDOUT_FILENO]);
	set_child_pid(pid);
}

static char	*get_exec_path(char **bin_path, char *executable)
{
	int		count;
	char	*path;
	char	*full_path;

	count = -1;
	path = NULL;
	full_path = executable;
	if (access(full_path, X_OK) == 0)
		return (full_path);
	while (bin_path[++count] != NULL)
	{
		path = ft_strjoin(bin_path[count], "/");
		full_path = ft_strjoinfree(path, executable, 'L');
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

static void	run_executable(t_execcmd *exec, t_context *ctx)
{
	exec->bin = get_exec_path(exec->sh->bin_path, exec->argv[0]);
	if (exec->bin)
		create_child_process(exec, ctx);
	else
	{
		ft_fprintf(2, "minishell: %s: command not found\n", exec->argv[0]);
		ctx->exit_code = 127;
	}
}

static t_bool	check_executable(char *bin, t_context *ctx)
{
	if (access(bin, F_OK) != 0)
	{
		ft_fprintf(2, "minishell: %s: %s\n", bin, strerror(2));
		ctx->exit_code = 127;
		return (FALSE);
	}
	if (access(bin, X_OK) != 0)
	{
		ft_fprintf(2, "minishell: %s: %s\n", bin, strerror(13));
		ctx->exit_code = 126;
		return (FALSE);
	}
	return (TRUE);
}

void	execute_command(t_execcmd *exec, t_context *ctx)
{
	if (ft_strchr(exec->argv[0], '/') == NULL)
	{
		if (execute_builtin(exec, ctx) == FALSE)
			run_executable(exec, ctx);
	}
	else if (check_executable(exec->argv[0], ctx))
		create_child_process(exec, ctx);
	set_exit_status(ctx->exit_code);
}
