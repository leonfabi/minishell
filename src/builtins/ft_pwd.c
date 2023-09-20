#include "minishell.h"

int	ft_pwd(t_execcmd *cmd)
{
	char	buffer[PATH_MAX];

	if (cmd->argv[1] != NULL)
	{
		general_error("pwd", ERR_ARG, NULL);
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
