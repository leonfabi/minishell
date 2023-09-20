#include "minishell.h"

void	add_child_pids(pid_t pid, t_context *ctx)
{
	ctx->pids[ctx->child] = pid;
}

void	copy_context(t_context *ctx, t_context next_ctx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ctx->exit_code = next_ctx.exit_code;
	ctx->child = next_ctx.child;
	while (next_ctx.pids[j] != 0)
	{
		ctx->pids[i++] = next_ctx.pids[j++];
	}
}
