#include "minishell.h"

int	*get_exit_status(void)
{
	static int	status;

	return (&status);
}

void	set_exit_status(int status)
{
	int		*exit_status;

	exit_status = get_exit_status();
	*exit_status = status;
}

void	child_exit_status(int status)
{
	printf("EXIT: %d\n", *get_exit_status());
	if (WIFEXITED(status))
		set_exit_status(WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		set_exit_status(WTERMSIG(status));
}

int	*get_child_pid(void)
{
	static pid_t	child_pid;

	return (&child_pid);
}

void	set_child_pid(int pid)
{
	pid_t	*child_pid;
	child_pid = get_child_pid();
	*child_pid = pid;
}
