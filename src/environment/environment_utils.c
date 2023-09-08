#include "minishell.h"

char	*get_env(char **env, char *search)
{
	size_t	len;

	len = ft_strlen(search);
	while (NULL != *env)
	{
		if (ft_strncmp(*env, search, len) == 0 && *(*env + len) == '=')
			return (ft_strdup((*env) + len + 1));
		++env;
	}
	return (NULL);
}

t_bool	check_env_variable(char *env, char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (ft_strncmp(env, name, len) != 0)
		return (FALSE);
	if (*(env + len) == '=')
		return (TRUE);
	return (FALSE);
}
