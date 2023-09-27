#include "libft.h"
#include "defines.h"
#include "executor.h"
#include "expander.h"
#include "signals.h"
#include "utils.h"

#define HEREDOC_PROMPT "\e[m\e[0;35m> \e[m"
#define HEREDOCERR "here-document delimited by end-of-file, wanted"

/* `<SUMMARY>`:
 * Checks if the current string read from readline is either NULL or
 * the delimiter specified by the user.
 * `<PARAM>`:
 * `input`: input string from readline;
 * `delim`: delimiter specified by the user;
 * `<RETURN>`:
 * Returns `TRUE` if the input is neither NULL nor equal to the delimiter.
 * Returns `FALSE` if the input is NULL or equal to the delimiter. */
static t_bool	check_line(char *input, char *delim)
{
	if (NULL == input)
	{
		ft_fprintf(2, "minishell: warning: %s -> '%s'\n", HEREDOCERR, delim);
		return (FALSE);
	}
	else if (ft_strcmp(input, delim) == 0)
	{
		adv_free(&input);
		return (FALSE);
	}
	return (TRUE);
}

/* `<SUMMARY>`:
 * Main loop for the heredoc function to get the input from the user.
 * `<PARAM>`:
 * `redir`: redirection node from the AST;
 * `ctx`: context holding information about the pipe and pid;
 * `<RETURN>`:
 * `Nothing`. */
static void	heredoc(t_redircmd *redir, t_context *ctx)
{
	char	*input;
	char	*delim;

	delim = redir->file;
	set_close_fd(ctx->fd[STDOUT_FILENO]);
	heredoc_child_handler();
	while (TRUE)
	{
		input = readline(HEREDOC_PROMPT);
		if (check_line(input, delim) == FALSE)
			break ;
		if (redir->expand == TRUE)
			input = expand_readline(input, *get_env_arr());
		ft_fprintf(ctx->fd[STDOUT_FILENO], "%s\n", input);
		adv_free(&input);
	}
}

/* `<SUMMARY>`:
 * Function that forks the process to get a child for the heredoc
 * function.
 * `<PARAM>`:
 * `redir`: redirection node from the AST;
 * `ctx`: context holding information about the pipe and pid;
 * `<RETURN>`:
 * `Nothing`. */
static void	fork_heredoc(t_redircmd *redir, t_context *ctx)
{
	pid_t	pid;

	pid = adv_fork();
	if (CHILD_FORK == pid)
	{
		close(ctx->fd[STDIN_FILENO]);
		heredoc(redir, ctx);
		if (ctx->fd_close >= 0)
			close(ctx->fd_close);
		here_cleanup();
		exit(EXIT_SUCCESS);
	}
	close(ctx->fd[STDOUT_FILENO]);
	heredoc_parent_handler();
	add_child_pids(pid, ctx);
	child_reaper(ctx);
	wait_user_signals();
}

void	execute_heredoc(t_redircmd *redir, t_context *ctx)
{
	t_context	here_ctx;
	int			here_fd[2];

	if (pipe(here_fd) == -1)
	{
		general_error("pipe", strerror(errno), NULL);
		ctx->error = TRUE;
		return ;
	}
	here_ctx = *ctx;
	here_ctx.fd[STDOUT_FILENO] = here_fd[STDOUT_FILENO];
	here_ctx.fd[STDIN_FILENO] = here_fd[STDIN_FILENO];
	here_ctx.fd_close = here_fd[STDOUT_FILENO];
	fork_heredoc(redir, &here_ctx);
	if (ctx->exit_code == EXIT_SUCCESS)
	{
		ctx->fd[STDIN_FILENO] = here_fd[STDIN_FILENO];
		exec_node(redir->cmd, ctx);
	}
}
