#include "defines.h"
#include "executor.h"
#include "utils.h"
#include "signals.h"

t_quit	executor_main(t_cmd *ast)
{
	t_context	ctx;

	if (ast == NULL)
		return (FALSE);
	ctx = (t_context){};
	ctx.fd[STDIN_FILENO] = STDIN_FILENO;
	ctx.fd[STDOUT_FILENO] = STDOUT_FILENO;
	ctx.fd_close = -1;
	ctx.exit_code = EXIT_SUCCESS;
	exec_node(ast, &ctx);
	child_reaper(&ctx);
	clean_ast(*get_ast_root());
	set_ast_root(NULL);
	set_exit_status(ctx.exit_code);
	return (*get_quit());
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
