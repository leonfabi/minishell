#include "minishell.h"

// TODO: ADD support for multiple export statements

t_bool	precheck_env_update(char *var)
{
	t_bool	check;
	char	*run;

	run = var;
	check = TRUE;
	check &= ft_isalpha(*run) | ('_' == *run);
	while (check == TRUE && ++*run != '\0' && *run != '=')
		check &= ft_isalnum(*run) | ('_' == *run);
	if (check == FALSE)
		printf("minishell: export: '%s': not a valid identifier\n", var);
	return (check);
}

t_bool	update_env_variables(char **env, char *var)
{
	char	**upd;
	t_bool	check;
	size_t	len;

	check = precheck_env_update(var);
	if (check == false)
		return (set_exit_status(1), FALSE);
	upd = env;
	len = ft_strlen_c(var, '=');
	while (NULL != *upd)
	{
		if (ft_strncmp(*upd, var, len))
			break ;
		++upd;
	}
	if (NULL != *upd)
	{
		free(*upd);
		*upd = NULL;
		*upd = ft_strdup(var);
	}
	if (NULL == *upd)
		return (set_exit_status(1), FALSE);
	return (TRUE);
}
