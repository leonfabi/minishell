#include "defines.h"
#include "executor.h"
#include "utils.h"

static void	choose_fd(const t_redircmd redir, const int *fd, t_context *ctx)
{
	if (redir.fd == 1)
		dup2(*fd, ctx->fd[STDOUT_FILENO]);
	else if (redir.fd == 0)
		dup2(*fd, ctx->fd[STDIN_FILENO]);
	close(*fd);
}

void	execute_redir(t_redircmd *redir, t_context *ctx)
{
	int				fd;

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
		choose_fd(*redir, &fd, ctx);
		if (redir->cmd->type == EXECUTE)
		{
			if (((t_execcmd *)redir->cmd)->argv[0] == NULL)
				exec_node(NULL, ctx);
			else
				exec_node(redir->cmd, ctx);
		}
		else
			exec_node(redir->cmd, ctx);
	}
}
