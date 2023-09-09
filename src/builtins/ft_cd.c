#include "minishell.h"

static void	update_pwd(t_main *sh)
{
	char	*update;

	update = NULL;
	update = ft_strjoinfree("OLDPWD=", get_env(sh->env, "PWD"), 'R');
	sh->env = update_env_variables(sh, update);
	free(update);
	update = NULL;
	update = ft_strjoinfree("PWD=", getcwd(NULL, 0), 'R');
	sh->env = update_env_variables(sh, update);
	free(update);
}

static int	ft_chdir(t_main *sh, char *dir)
{
	int		exit_code;

	if (chdir(dir) == -1)
	{
		ft_fprintf(2, "minishell: cd: '%s': %s\n", dir, strerror(errno));
		exit_code = EXIT_FAILURE;
	}
	else
		update_pwd(sh);
	exit_code = EXIT_SUCCESS;
	return (exit_code);
}

static int	ft_cd_home(t_main *sh)
{
	char	*home;
	int		exit_code;

	home = get_env(sh->env, "HOME");
	exit_code = EXIT_SUCCESS;
	if (NULL == home)
	{
		print(STDERR_FILENO, "minishell: cd: HOME not set\n");
		exit_code = EXIT_FAILURE;
	}
	else
	{
		exit_code = ft_chdir(sh, home);
		free(home);
	}
	return (exit_code);
}

int	ft_cd(t_execcmd *cmd)
{
	int		arrlen;
	int		exit_code;

	arrlen = ft_arrlen((const char **)cmd->argv);
	if (arrlen == 1)
		exit_code = ft_cd_home(cmd->sh);
	else if (arrlen == 2)
		exit_code = ft_chdir(cmd->sh, cmd->argv[1]);
	else
	{
		print(STDERR_FILENO, "minishell: cd: too many arguments\n");
		exit_code = EXIT_FAILURE;
	}
	return (exit_code);
}
