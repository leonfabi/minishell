#include "minishell.h"

// TODO: ADD update for multiple unset variables

t_bool	ft_unset(char **env, char *name)
{
	char	**delete;
	char	**shift;
	size_t	len;

	set_exit_status(EXIT_SUCCESS);
	len = ft_arrlen((const char **)env);
	if (0 == len)
		return (FALSE);
	delete = env;
	while (NULL != *delete)
	{
		if (check_env_variable(*delete, name) == TRUE)
			break ;
		++delete;
	}
	shift = delete;
	free(*delete);
	while (shift < env + len)
	{
		*shift = *(shift + 1);
		++shift;
	}
	*shift = NULL;
	return (TRUE);
}
