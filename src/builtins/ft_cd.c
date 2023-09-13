#include "minishell.h"

/* `<SUMMARY>`:
 * Updates the PWD and OLDPWD environment variable after changing the
 * directory.
 * `<PARAM>`:
 * `sh`: main struct containing the environment variable array of strings;
 * `<RETURN>`:
 * Nothing. */
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

/* `<SUMMARY>`:
 * Changes the directory to the given `dir` variable.
 * `<PARAM>`:
 * `sh`: main struct containing the environment variable array of strings;
 * `dir`: string of directory the user wants to change to;
 * `<RETURN>`:
 * Returns `exit_code` respective to if the cd succeeded or failed. */
static int	ft_chdir(t_main *sh, char *dir)
{
	int		exit_code;
	
	exit_code = EXIT_SUCCESS;
	if (dir == NULL)
		exit_code = EXIT_FAILURE;
	else if (chdir(dir) == -1)
	{
		ft_fprintf(2, "minishell: cd: '%s': %s\n", dir, strerror(errno));
		exit_code = EXIT_FAILURE;
	}
	else
		update_pwd(sh);
	return (exit_code);
}

/* `<SUMMARY>`:
 * Function for `-` and `~` input for the cd command.
 * Changes directory to OLDPWD or HOME, accordingly.
 * `<PARAM>`:
 * `sh`: main struct containing the environment variable array of strings;
 * `dir`: string of directory the user wants to change to;
 * `<RETURN>`:
 * Returns `exit_code` respective to if the cd succeeded or failed. */
static int	dir_specials(t_main *sh, char *dir)
{
	char	*replace;
	char	*tmp;
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	replace = NULL;
	if (*dir == '-')
		replace = get_env(sh->env, "OLDPWD");
	else if (*dir == '~')
		replace = get_env(sh->env, "HOME");
	if (*dir == '-' && NULL == replace)
		print(2, "minishell: cd: OLDPWD not set\n");
	else if (*dir == '~' && NULL == replace)
		print(2, "minishell: cd: HOME not set\n");
	exit_code = ft_chdir(sh, replace);
	if (NULL != replace)
		free(replace);
	return (exit_code);
}

/* `<SUMMARY>`:
 * Function for changing the directory to HOME.
 * `<PARAM>`:
 * `sh`: main struct containing the environment variable array of strings;
 * `<RETURN>`:
 * Returns `exit_code` respective to if the cd succeeded or failed. */
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

/* `<SUMMARY>`:
 * Function to verify if the given special character is given
 * correctly to the cd command. Checks for `-` and `~`.
 * `<PARAM>`:
 * `dir`: string with special symbol for the cd command;
 * `<RETURN>`:
 * `TRUE` if symbol is verified, otherwise `FALSE`. */
static t_bool	symbol_verify(char *dir)
{
	if (*dir == '-' && *(dir + 1) == '\0')
		return (TRUE);
	if (*dir == '~' && *(dir + 1) == '\0')
		return (TRUE);
	return (FALSE);
}

int	ft_cd(t_execcmd *cmd)
{
	int		arrlen;
	int		exit_code;

	arrlen = ft_arrlen((const char **)cmd->argv);
	if (arrlen == 1)
		exit_code = ft_cd_home(cmd->sh);
	else if (symbol_verify(cmd->argv[1]) == TRUE && arrlen == 2)
		exit_code = dir_specials(cmd->sh, cmd->argv[1]);
	else if (arrlen == 2)
		exit_code = ft_chdir(cmd->sh, cmd->argv[1]);
	else
	{
		print(STDERR_FILENO, "minishell: cd: too many arguments\n");
		exit_code = EXIT_FAILURE;
	}
	return (exit_code);
}
