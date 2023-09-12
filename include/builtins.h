#ifndef BUILTINS_H
# define BUILTINS_H

# include "defines.h"

typedef int	(*t_builtin_p)(t_execcmd *);

int		ft_cd(t_execcmd *cmd);
int		ft_exit(t_execcmd *cmd);
int		ft_echo(t_execcmd *cmd);
int		ft_pwd(t_execcmd *cmd);
int		print(int fd, char *str);

/* `<SUMMARY>`:
 * Print all name and value pairs of the environment variable.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns `EXIT_SUCCESS` on success. */
int		ft_env(t_execcmd *cmd);

/* `<SUMMARY>`:
 * Removes the corresponding var from the environment variables.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns the exit status of the unset function (always true)*/
int	ft_unset(t_execcmd *cmd);

int		ft_export(t_execcmd *cmd);

char	**sort_array(char **arr);

/* `<SUMMARY>`:
 * Checks if the given variable is a valid variable for
 * an environment variable in our shell.
 * `<PARAM>`:
 * `var`: string that represents the variable name;
 * `<RETURN>`:
 * Returns `TRUE` on success and `FALSE` on fail. */
t_bool	precheck_env_update(char *var);

void	declare_x(char **env);

#endif
