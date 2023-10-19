/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:50:45 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:50:46 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "executor.h"

void	add_child_pids(pid_t pid, t_context *ctx)
{
	ctx->pids[ctx->child] = pid;
	++ctx->child;
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
		ctx->pids[i] = next_ctx.pids[j];
		++i;
		++j;
	}
}

/* `<SUMMARY>`:
 * Function for setting the exit code accordingly to the childs
 * exit code. WIFEXITED is used to determine the return code
 * if the child exited normally, WIFSIGNALED determines the
 * return code if the child terminated because of a signal.
 * `<PARAM>`:
 * `status`: return value received by waitpid;
 * `ctx`: context for handling the correct redirection;
 * `<RETURN>`:
 * Nothing. */
static void	set_child_exit_status(int status, t_context *ctx)
{
	if (WIFEXITED(status))
	{
		ctx->exit_code = WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status))
	{
		ctx->exit_code = WTERMSIG(status) + 128;
	}
}

void	child_reaper(t_context *ctx)
{
	int		i;
	int		status;

	i = -1;
	status = 0;
	while (ctx->pids[++i] != 0)
	{
		waitpid(ctx->pids[i], &status, 0);
		--ctx->child;
	}
	if (ctx->error == TRUE || ctx->exit_code)
	{
		return ;
	}
	set_child_exit_status(status, ctx);
}
