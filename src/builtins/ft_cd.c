#include "minishell.h"

// static void	update_pwd(char ***env, char control)
// {
// 	char	*update;
// 
// 	if (control == 'C')
// 	{
// 		update = ft_strjoinfree("PWD=", getcwd(NULL, 0), 'R');
// 		update_env_variables(*env, update);
// 		free(update);
// 	}
// 	else if (control == 'P')
// 	{
// 		update = ft_strjoinfree("OLDPWD=", get_env(*env, "PWD"), 'R');
// 		update_env_variables(*env, update);
// 		free(update);
// 	}
// }

static void	update_pwd(char ***env)
{
	char	*update;

	update = NULL;
	update = ft_strjoinfree("OLDPWD=", get_env(*env, "PWD"), 'R');
	update_env_variables(*env, update);
	free(update);
	update = NULL;
	update = ft_strjoinfree("PWD=", getcwd(NULL, 0), 'R');
	update_env_variables(*env, update);
	free(update);
}

static int	ft_chdir(char ***env, char *dir)
{
	int		exit_code;

	if (chdir(dir) == -1)
	{
		ft_fprintf(2, "minishell: cd: '%s': %s\n", dir, strerror(errno));
		exit_code = EXIT_FAILURE;
	}
	else
		update_pwd(env);
	exit_code = EXIT_SUCCESS;
	return (exit_code);
}

static int	ft_cd_home(char ***env)
{
	char	*home;
	int		exit_code;

	home = get_env(*env, "HOME");
	exit_code = EXIT_SUCCESS;
	if (NULL == home)
	{
		print(STDERR_FILENO, "minishell: cd: HOME not set");
		exit_code = EXIT_FAILURE;
	}
	else
	{
		exit_code = ft_chdir(env, home);
		free(home);
	}
	return (exit_code);
}

int	ft_cd(t_execcmd *cmd, char **env)
{
	int		arrlen;
	int		exit_code;

	arrlen = ft_arrlen((const char **)cmd->argv);
	if (arrlen == 1)
		exit_code = ft_cd_home(&env);
	else if (arrlen == 2)
		print(STDOUT_FILENO, "TEST");
	else
	{
		print(STDERR_FILENO, "minishell: cd: too many arguments\n");
		exit_code = EXIT_FAILURE;
	}
	return (exit_code);
}
