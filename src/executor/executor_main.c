#include "minishell.h"

void	execute_heredoc(t_redircmd *redir, t_context *ctx)
{

}

void	execute_redir(t_redircmd *redir, t_context *ctx)
{
	int	fd;

	if (redir->type == O_HEREDOC)
		return (execute_heredoc(redir, ctx));
	else
	{
		fd = open(redir->file, redir->mode, 0644);
		if (fd == -1)
		{
			ft_fprintf(2, "minishell: %s: %s\n", redir->file, strerror(errno));
			ctx->error = TRUE;
			return ;
		}
		if (redir->fd == 1)
			dup2(fd, STDOUT_FILENO);
		else if (redir->fd == 0)
			dup2(fd, STDIN_FILENO);
		close(fd);
	}
	exec_node(redir->cmd, ctx);
}

void	execute_pipe(t_pipecmd *pcmd, t_context *ctx)
{
	t_context	next_ctx;
	int			pipe_fd[2];

	ctx->pipeline = TRUE;
	if (pipe(pipe_fd) == -1)
	{
		ft_fprintf(2, "minishell: pipe: %s\n", strerror(errno));
		ctx->error = TRUE;
		return ;
	}
	next_ctx = *ctx;
	next_ctx.fd[STDOUT_FILENO] = pipe_fd[STDOUT_FILENO];
	next_ctx.fd_close = pipe_fd[STDIN_FILENO];
	exec_node(pcmd->left, &next_ctx);
	copy_context(ctx, next_ctx);
	next_ctx = *ctx;
	next_ctx.fd[STDIN_FILENO] = pipe_fd[STDIN_FILENO];
	next_ctx.fd_close = pipe_fd[STDOUT_FILENO];
	exec_node(pcmd->right, &next_ctx);
	copy_context(ctx, next_ctx);
	close(pipe_fd[STDIN_FILENO]);
	close(pipe_fd[STDOUT_FILENO]);
}

void	set_child_exit_status(int status, t_context *ctx)
{
	if (WIFEXITED(status))
		ctx->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		ctx->exit_code = WTERMSIG(status) + 128;
}

void	child_reaper(t_context *ctx)
{
	int		i;
	int		status;

	i = -1;
	status = 0;
	while (ctx->pids[++i] != 0)
		waitpid(ctx->pids[i], &status, 0);
	if (ctx->error == TRUE || ctx->exit_code)
	{
		return ;
	}
	set_child_exit_status(status, ctx);
}

t_bool	executor_main(t_cmd *ast)
{
	t_context	ctx;

	if (ast == NULL)
		return (FALSE);
	ctx = (t_context){};
	ctx.fd[STDIN_FILENO] = STDIN_FILENO;
	ctx.fd[STDOUT_FILENO] = STDOUT_FILENO;
	ctx.fd_close = -1;
	ctx.exit_code = *get_exit_status();
	exec_node(ast, &ctx);
	child_reaper(&ctx);
	clean_ast(*get_ast_root());
	set_ast_root(NULL);
	set_child_pid(-1);
	set_exit_status(ctx.exit_code);
	return (ctx.quit);
}

void	exec_node(t_cmd *ast, t_context *ctx)
{
	if (ctx->error == TRUE || NULL == ast)
		return ;
	if (ast->type == EXECUTE)
		execute_command((t_execcmd *) ast, ctx);
	else if (ast->type == REDIR)
		execute_redir((t_redircmd *) ast, ctx);
	else if (ast->type == PIPE)
		execute_pipe((t_pipecmd *) ast, ctx);
}

