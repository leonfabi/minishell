#include "minishell.h"

t_bool	check_env_variable(char *env, char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (ft_strncmp(env, name, len) != 0)
		return (FALSE);
	if (*(env + len) == '_' || (ft_isalnum(*(env + len)) == TRUE))
		return (FALSE);
	return (TRUE);
}
