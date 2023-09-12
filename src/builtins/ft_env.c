#include "minishell.h"

int	ft_env(t_execcmd *cmd)
{
	char	**run;

	run = cmd->sh->env;
	while (*run != NULL)
	{
		printf("%s\n", *run);
		++run;
	}
	set_exit_status(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
