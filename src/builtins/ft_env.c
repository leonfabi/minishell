#include "minishell.h"

int	ft_env(t_execcmd *cmd)
{
	char	**run;

	run = cmd->sh->env;
	while (*run != NULL)
	{
		// if (*run + ft_strlen_c(*run, '='))
		printf("%s\n", *run);
		++run;
	}
	set_exit_status(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
