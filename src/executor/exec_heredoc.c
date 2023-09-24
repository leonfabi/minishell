#include "libft.h"
#include "defines.h"
#include "executor.h"
#include "expander.h"
#include "utils.h"

#define HEREDOC_PROMPT "\e[m\e[0;35m> \e[m"

void	heredoc(t_redircmd *redir, t_context *ctx)
{
	char	*input;
	char	*delim;

	input = readline(HEREDOC_PROMPT);
	delim = redir->file;
	while (input && (ft_strcmp(input, delim) != 0))
	{
		if (redir->expand == TRUE)
			input = expand_readline(input, *get_env_arr());
		ft_fprintf(ctx->fd[1], "%s\n", input);
		adv_free(&input);
		input = readline(HEREDOC_PROMPT);
	}
	adv_free(&input);
}

void	pipe_heredoc(t_redircmd *redir, t_context *ctx)
{
	pid_t	pid;
	int		fd_here[2];

	if (pipe(fd_here) == -1)
	{
		general_error("pipe", strerror(errno), NULL);
		ctx->error = TRUE;
		return ;
	}
	pid = adv_fork();
	if (CHILD_FORK == pid)
	{
		close(fd_here[0]);
		heredoc(redir, ctx);
		close(fd_here[1]);
	}
	close(fd_here[1]);
	add_child_pids(pid, ctx);
	child_reaper(ctx);
	dup2(fd_here[0], STDIN_FILENO);
	close(fd_here[0]);
	exec_node(redir->cmd, ctx);
}

