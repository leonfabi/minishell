#include "defines.h"
#include "executor.h"
#include "utils.h"

void	execute_pipe(t_pipecmd *pcmd, t_context *ctx)
{
	t_context	next_ctx;
	int			pipe_fd[2];

	ctx->pipeline = TRUE;
	if (pipe(pipe_fd) == -1)
	{
		general_error("pipe", strerror(errno), NULL);
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
