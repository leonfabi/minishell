# include "minishell.h"

char	*get_exec_path(char **bin_path, char *executable)
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
		// full_path = ft_strjoin(path, executable);
		full_path = ft_strjoinfree(path, executable, 'L');
		// free(path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

void	execute_node(t_execcmd *exec)
{

// Is builtin
	exec->bin = get_exec_path(exec->sh->bin_path, exec->argv[0]);
	if (exec->bin == NULL)
		printf("minishell: command not found: %s\n", exec->argv[0]);
	else
	{
		if (execve(exec->bin, exec->argv, exec->sh->env) == -1)
			perror("Execve error: ");
		free(exec->bin);
	}
}

void	execute_heredoc(t_redircmd *redir)
{

}

void	execute_redir(t_redircmd *redir)
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
	executor(redir->cmd);
}

void	execute_pipe(t_pipecmd *pcmd)
{
	int		pipe_fd[2];
	pid_t	id;

	if (pipe(pipe_fd) == -1)
		perror("Pipe error");
	id = fork();
	if (id == -1)
		perror("Fork error");
	if (id == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		executor(pcmd->left);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		executor(pcmd->right);
	}
}

void	executor(t_cmd *ast)
{
	if (ast->type == EXECUTE)
		execute_node((t_execcmd *) ast);
	else if (ast->type == REDIR)
		execute_redir((t_redircmd *) ast);
	else if (ast->type == PIPE)
		execute_pipe((t_pipecmd *) ast);
}

// int main(int argc, char* argv[])
// {
// 	int	fd[2];
// 	// fd[0] read; fd[1] write
// 	if (pipe(fd) == -1)
// 	{
// 		printf("An error ocurred with opening the pipe\n");
// 		return (1);
// 	}
// 	int	id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		int	x;
// 		printf("Input a number to the child process: ");
// 		scanf("%d", &x);
// 		write(fd[1], &x, sizeof(int));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		int	y;
// 		read(fd[0], &y, sizeof(int));
// 		close(fd[0]);
// 		printf("Parent print number from child: %d\n", y);
// 	}
// 	// int	id = fork();
// 	// int	n;
// 	// int	i;
// 	// if (id == 0)
// 	// 	n = 1;
// 	// else
// 	// 	n = 6;
// 	// printf("Current id: %d, parent id: %d\n", getpid(), getppid());
// 	// if (id != 0)
// 	// 	wait(NULL);
// 	// for (i = n; i < n + 5; i++)
// 	// {
// 	// 	printf("%d", i);
// 	// 	fflush(stdout);
// 	// }
// 	// if (id == 0)
// 	// 	printf("Hello from child process\n");
// 	// else
// 	// 	printf("Hello from the main process\n");
// 	return 0;
// }
