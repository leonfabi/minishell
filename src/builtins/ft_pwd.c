#include "minishell.h"

int	ft_pwd(t_execcmd *cmd)
{
	char	buffer[PATH_MAX];

	if (cmd->argv[1] != NULL)
	{
		ft_fprintf(STDERR_FILENO, "pwd: too many arguments\n");
		set_exit_status(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	if (getcwd(buffer, PATH_MAX) == NULL)
	{
		set_exit_status(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	printf("%s\n", buffer);
	set_exit_status(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
