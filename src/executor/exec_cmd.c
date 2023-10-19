/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:50:41 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:50:42 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "executor.h"
#include "utils.h"
#include "signals.h"

/* `<SUMMARY>`:
 * Function for checking if an executable given as relative or
 * absolute path is executable or not and sets the
 * error code accordingly.
 * `<PARAM>`:
 * `bin`: executable that is given as a command;
 * `<RETURN>`:
 * `TRUE` if everything is fine, `FALSE` if not. */
static int	check_executable(char *bin)
{
	struct stat		statbuf;

	if (access(bin, F_OK) != 0)
	{
		general_error(bin, "command not found", NULL);
		return (127);
	}
	if (access(bin, X_OK) != 0)
	{
		general_error(bin, strerror(13), NULL);
		return (126);
	}
	stat(bin, &statbuf);
	if (S_ISDIR(statbuf.st_mode) != 0)
	{
		general_error(bin, strerror(21), NULL);
		return (126);
	}
	return (TRUE);
}

/* `<SUMMARY>`:
 * Function for creating a child process to execute the given
 * command in a child and also close the appropriate file descriptor
 * if necessary.
 * `<PARAM>`:
 * `exec`: current execution node of the AST;
 * `ctx`: context for handling the correct redirection;
 * `<RETURN>`:
 * Nothing. */
static void	create_child_process(t_execcmd *exec, t_context *ctx)
{
	int			pid;

	pid = adv_fork();
	if (CHILD_FORK == pid)
	{
		signal(SIGINT, SIG_DFL);
		dup2(ctx->fd[STDIN_FILENO], STDIN_FILENO);
		dup2(ctx->fd[STDOUT_FILENO], STDOUT_FILENO);
		if (ctx->fd_close >= 0)
			close(ctx->fd_close);
		execve(exec->bin, exec->argv, exec->sh->env);
		ctx->exit_code = check_executable(exec->bin);
		msh_cleanup(exec->sh);
		exit(ctx->exit_code);
	}
	if (ctx->fd[STDIN_FILENO] != STDIN_FILENO)
		close(ctx->fd[STDIN_FILENO]);
	if (ctx->fd[STDOUT_FILENO] != STDOUT_FILENO)
		close(ctx->fd[STDOUT_FILENO]);
	block_parent_handler();
	add_child_pids(pid, ctx);
}

/* `<SUMMARY>`:
 * Function for finding the correct path to the executable that is
 * being provided.
 * `<PARAM>`:
 * `bin_path`: array of strings with the current PATH variable;
 * `bin`: executable that is given as a command;
 * `<RETURN>`:
 * Full path to the executable or NULL if not found. */
static char	*get_exec_path(char **bin_path, char *bin)
{
	int		count;
	char	*path;
	char	*full_path;

	if (NULL == bin_path)
		return (ft_strdup(bin));
	count = -1;
	path = NULL;
	full_path = bin;
	if (access(full_path, X_OK) == 0)
		return (ft_strdup(full_path));
	while (bin_path[++count] != NULL)
	{
		path = ft_strjoin(bin_path[count], "/");
		full_path = ft_strjoinfree(path, bin, 'L');
		if (access(full_path, X_OK) == 0)
			return (full_path);
		adv_free(&full_path);
	}
	return (ft_strdup(bin));
}

/* `<SUMMARY>`:
 * Function for checking if the executable is in the current PATH
 * and if not sets the error code to 127 `command not found`.
 * `<PARAM>`:
 * `exec`: current execution node of the AST;
 * `ctx`: context for handling the correct redirection;
 * `<RETURN>`:
 * Nothing. */
static void	run_executable(t_execcmd *exec, t_context *ctx)
{
	exec->bin = get_exec_path(exec->sh->bin_path, exec->argv[0]);
	create_child_process(exec, ctx);
}

void	execute_command(t_execcmd *exec, t_context *ctx)
{
	if (ft_strchr(exec->argv[0], '/') == NULL)
	{
		if (execute_builtin(exec, ctx) == FALSE)
			run_executable(exec, ctx);
	}
	else
	{
		exec->bin = ft_strdup(exec->argv[0]);
		create_child_process(exec, ctx);
	}
	set_exit_status(ctx->exit_code);
}
