#include "minishell.h"

int	ft_env(char **env)
{
	char	**run;

	run = env;
	while (*run != NULL)
	{
		// if (*run + ft_strlen_c(*run, '='))
		printf("%s\n", *run);
		++run;
	}
	set_exit_status(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
