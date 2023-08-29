#include "minishell.h"

t_bool	env(char **env)
{
	char	**run;

	run = env;
	while (*run != NULL)
	{
		if (*run + ft_strlen_c(*run, '='))
			printf("%s\n", *run);
		++run;
	}
	set_exit_status(0);
	return (TRUE);
}
