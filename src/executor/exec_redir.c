#include "defines.h"
#include "executor.h"
#include "utils.h"

void	execute_redir(t_redircmd *redir, t_context *ctx)
{
	int	fd;

	if (redir->mode == O_HEREDOC)
		execute_heredoc(redir, ctx);
	else
	{
		fd = open(redir->file, redir->mode, 0644);
		if (fd == -1)
		{
			general_error(redir->file, strerror(errno), NULL);
			ctx->exit_code = EXIT_FAILURE;
			ctx->error = TRUE;
			return ;
		}
		if (redir->fd == 1)
			dup2(fd, STDOUT_FILENO);
		else if (redir->fd == 0)
			dup2(fd, STDIN_FILENO);
		close(fd);
		exec_node(redir->cmd, ctx);
	}
}
