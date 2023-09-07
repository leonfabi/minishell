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
		full_path = ft_strjoin(path, executable);
		free(path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

void	execute_node(t_execcmd *exec, char **env, char **bin_path)
{
	char	*full_path;

	full_path = get_exec_path(bin_path, exec->argv[0]);
	if (full_path == NULL)
		printf("minishell: command not found: %s\n", exec->argv[0]);
	else
	{
		if (execve(full_path, exec->argv, env) == -1)
			perror("Execve error: ");
		free(full_path);
	}
}

void	execute_pipe(t_pipecmd *pipe)
{

}

void	executor(t_cmd *ast, char **env, char **bin_path)
{
	if (ast->type == EXECUTE)
		execute_node((t_execcmd *) ast, env, bin_path);
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