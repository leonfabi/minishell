#include "minishell.h"

static char	**append_env_variable(char **env, char *var)
{
	int		arrlen;
	char	**new_env;
	int		i;

	arrlen = ft_arrlen((const char **)env);
	new_env = ft_resize_array(env, arrlen, arrlen + 1);
	if (ft_strchr(var, '=') == NULL)
		new_env[arrlen] = ft_strjoin(var, "=");
	else
		new_env[arrlen] = ft_strdup(var);
	return (new_env);
}

static char	*replace_env_variable(char *env, char *var)
{
	if (ft_strncmp(env, var, ft_strlen_c(var, '=') + 1) != 0)
		return (env);
	free(env);
	return (ft_strdup(var));
}

char	**update_env_variables(t_main *sh, char *var)
{
	int		i;
	t_bool	check;
	t_bool	replace;
	size_t	len;

	check = precheck_env_update(var);
	replace = FALSE;
	if (check == FALSE)
		return (sh->env);
	i = 0;
	len = ft_strlen_c(var, '=');
	while (NULL != sh->env[i])
	{
		if (ft_strncmp(sh->env[i], var, len) == 0 && sh->env[i][len] == '=')
		{
			replace = TRUE;
			break ;
		}
		++i;
	}
	if (replace == TRUE)
		sh->env[i] = replace_env_variable(sh->env[i], var);
	else
		sh->env = append_env_variable(sh->env, var);
	return (sh->env);
}

int	ft_export(t_execcmd *cmd)
{
	int		arrlen;
	int		i;

	i = 0;
	arrlen = ft_arrlen((const char **)cmd->argv);
	if (arrlen == 1)
		declare_x(cmd->sh->env);
	while (++i < arrlen)
	{
		cmd->sh->env = update_env_variables(cmd->sh, cmd->argv[i]);
	}
	if (*get_exit_status() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	set_exit_status(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
