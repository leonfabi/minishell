#include "minishell.h"

static t_bool	run_unset(char **env, char *name)
{
	char	**delete;
	char	**shift;
	size_t	len;

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

int	ft_unset(t_execcmd *cmd, char **env)
{
	int		arrlen;
	int		i;

	i = 0;
	set_exit_status(EXIT_SUCCESS);
	arrlen = ft_arrlen((const char **)cmd->argv);
	if (NULL == cmd->argv[1])
		return (EXIT_SUCCESS);
	while (NULL == cmd->argv[++i])
		run_unset(env, cmd->argv[i]);
	return (EXIT_SUCCESS);
}
