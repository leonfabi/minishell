#include "minishell.h"
static void	spawn_process(char **argv, t_context *ctx);
static void	run_executable(t_execcmd *exec, t_context *ctx);

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

void	execute_command(t_execcmd *exec, t_context *ctx)
{
	if (ft_strchr(exec->argv[0], '/') == NULL)
	{
		if (execute_builtin(exec, ctx) == FALSE)
			run_executable(exec, ctx);
	}
	else if (is_executable(argv[0], ctx))
		spawn_process(argv, ctx);
	set_exit_status(ctx->exit_code);
}

static void	run_executable(t_execcmd *exec, t_context *ctx)
{
	char	*fullpath;

	fullpath = search_path(argv[0]);
	if (fullpath)
	{
		free(argv[0]);
		argv[0] = fullpath;
		spawn_process(argv, ctx);
	}
	else
	{
		msh_error(argv[0], "command not found", 0);
		ctx->retcode = 127;
	}
}

static void	spawn_process(char **argv, t_context *ctx)
{
	int			pid;
	extern char	**environ;

	wait_child_signals();
	pid = pfork();
	if (pid == FORKED_CHILD)
	{
		dup2(ctx->fd[STDIN_FILENO], STDIN_FILENO);
		dup2(ctx->fd[STDOUT_FILENO], STDOUT_FILENO);
		if (ctx->fd_close >= 0)
			close(ctx->fd_close);
		execve(argv[0], argv, environ);
		exit(EXIT_FAILURE);
	}
	if (ctx->fd[STDIN_FILENO] != STDIN_FILENO)
		close(ctx->fd[STDIN_FILENO]);
	if (ctx->fd[STDOUT_FILENO] != STDOUT_FILENO)
		close(ctx->fd[STDOUT_FILENO]);
	enqueue(pid, ctx);
}
