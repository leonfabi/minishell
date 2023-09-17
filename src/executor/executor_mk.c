#include "minishell.h"

static char	*get_exec_path(char **bin_path, char *executable)
{
	int		count;
	char	*path;
	char	*full_path;

	count = -1;
	path = NULL;
	full_path = executable;
	if (access(full_path, X_OK) == 0)
		return (full_path);
	while (bin_path[++count] != NULL)
	{
		path = ft_strjoin(bin_path[count], "/");
		full_path = ft_strjoinfree(path, executable, 'L');
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

t_builtin_p	is_builtin(t_execcmd *exec)
{
	int					id;
	static const char			*ft_builtin_name[] = {"cd", "echo", "env", "exit", "export", \
	"pwd", "unset"};
	static const t_builtin_p	ft_builtin_p[] = {&ft_cd, &ft_echo, &ft_env, &ft_exit, \
	&ft_export, &ft_pwd, &ft_unset};

	id = 0;
	while (ft_builtin_name[id])
	{
		if (ft_strcmp(exec->argv[0],ft_builtin_name[id]) == 0)
			return (ft_builtin_p[id]);
		id++;
	}
	return (NULL);
}

int	execute_node(t_execcmd *exec, int fd)
{
	pid_t		id;
	int			status;

	id = fork();
	if (id == 0)
	{
		if (fd != STDIN_FILENO)
		{
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		exec->bin = get_exec_path(exec->sh->bin_path, exec->argv[0]);
		if (NULL == exec->bin)
		{
			print(2, "minishell: exec: command not found");
			exit(127);
		}
		else
		{
			if (execve(exec->bin, exec->argv, exec->sh->env) == -1)
				perror("Execve error: ");
			free(exec->bin);
			exit(0);
		}
	}
	else
	{
		if (fd != STDIN_FILENO)
			close(fd);
	}
	return (0);
}

// int	execute_node(t_execcmd *exec, int fd)
// {
// 	pid_t		id;
// 	int			status;
// 	t_builtin_p	builtin;
// 
// 	builtin = is_builtin(exec);
// 	if (builtin != NULL)
// 		return (builtin((t_execcmd *)exec));
// 	id = fork();
// 	if (id == 0)
// 	{
// 		exec->bin = get_exec_path(exec->sh->bin_path, exec->argv[0]);
// 		if (exec->bin == NULL)
// 			printf("minishell: command not found: %s\n", exec->argv[0]);
// 		else
// 		{
// 			if (execve(exec->bin, exec->argv, exec->sh->env) == -1)
// 				perror("Execve error: ");
// 			free(exec->bin);
// 			exit(0);
// 		}
// 	}
// 	waitpid(id, &status, 0);
// 	if (WIFEXITED(status) == TRUE)
// 		set_exit_status(WEXITSTATUS(status));
// 	return (0);
// }

void	execute_heredoc(t_redircmd *redir)
{

}

void	execute_redir(t_redircmd *redir, int fd)
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
	executor(redir->cmd, fd);
}

void	execute_pipe(t_pipecmd *pcmd, int fd)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		perror("Pipe error");
	executor_mk(pcmd->left, fd);
	close(pipe_fd[1]);
	executor_mk(pcmd->right, pipe_fd[0]);
	close(pipe_fd[0]);
}

void	executor_mk(t_cmd *ast, int fd)
{
	if (ast == NULL)
		return ;
	if (ast->type == EXECUTE)
		execute_node((t_execcmd *) ast, fd);
	else if (ast->type == REDIR)
		execute_redir((t_redircmd *) ast, fd);
	else if (ast->type == PIPE)
		execute_pipe((t_pipecmd *) ast, fd);
}

