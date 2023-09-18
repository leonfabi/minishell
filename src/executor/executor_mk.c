#include "minishell.h"

// int	execute_node(t_execcmd *exec, t_context *ctx)
// {
// 	pid_t		id;
// 	int			status;
// 
// 	id = fork();
// 	if (id == 0)
// 	{
// 		if (fd != STDIN_FILENO)
// 		{
// 			dup2(fd, STDIN_FILENO);
// 			close(fd);
// 		}
// 		exec->bin = get_exec_path(exec->sh->bin_path, exec->argv[0]);
// 		if (NULL == exec->bin)
// 		{
// 			print(2, "minishell: exec: command not found");
// 			exit(127);
// 		}
// 		else
// 		{
// 			if (execve(exec->bin, exec->argv, exec->sh->env) == -1)
// 				perror("Execve error: ");
// 			free(exec->bin);
// 			exit(0);
// 		}
// 	}
// 	else
// 	{
// 		if (fd != STDIN_FILENO)
// 			close(fd);
// 	}
// 	return (0);
// }

void	execute_heredoc(t_redircmd *redir)
{

}

void	execute_redir(t_redircmd *redir, t_context *ctx)
{
	int	fd;

	if (redir->type == O_HEREDOC)
		return (execute_heredoc(redir));
	fd = open(redir->file, redir->mode, 0644);
	if (fd == -1)
		perror("minishell: ");
	if (redir->fd == 1)
		dup2(fd, STDOUT_FILENO);
	else if (redir->fd == 0)
		dup2(fd, STDIN_FILENO);
	exec_ast(redir->cmd, ctx);
}

void	execute_pipe(t_pipecmd *pcmd, t_context *ctx)
{
	t_context	next_ctx;
	int			pipe_fd[2];

	ctx->pipeline = TRUE;
	// FIX: ERROR handling
	if (pipe(pipe_fd) == -1)
		perror("Pipe error");
	next_ctx = *ctx;
	next_ctx.fd[STDOUT_FILENO] = pipe_fd[STDOUT_FILENO];
	next_ctx.fd_close = pipe_fd[STDIN_FILENO];
	exec_ast(pcmd->left, &next_ctx);
	next_ctx = *ctx;
	next_ctx.fd[STDIN_FILENO] = pipe_fd[STDIN_FILENO];
	next_ctx.fd_close = pipe_fd[STDOUT_FILENO];
	exec_ast(pcmd->right, &next_ctx);
	close(pipe_fd[STDIN_FILENO]);
	close(pipe_fd[STDOUT_FILENO]);
}

void	executor_main(t_cmd *ast)
{
	t_context	ctx;
	int			status;

	ctx = (t_context){};
	ctx.fd[STDIN_FILENO] = STDIN_FILENO;
	ctx.fd[STDOUT_FILENO] = STDOUT_FILENO;
	ctx.fd_close = -1;
	ctx.exit_code = *get_exit_status();
	exec_ast(ast, &ctx);
	set_exit_status(ctx.exit_code);
	if (*get_child_pid() != -1)
	{
		waitpid(*get_child_pid(), &status, 0);
		child_exit_status(status);
	}
	clean_ast(*get_ast_root());
	set_child_pid(-1);
}

void	exec_ast(t_cmd *ast, t_context *ctx)
{
	if (ast == NULL)
		return ;
	if (ast->type == EXECUTE)
		execute_command((t_execcmd *) ast, ctx);
	else if (ast->type == REDIR)
		execute_redir((t_redircmd *) ast, ctx);
	else if (ast->type == PIPE)
		execute_pipe((t_pipecmd *) ast, ctx);
}

