#ifndef BUILTINS_H
# define BUILTINS_H

#include "environment.h"
#include "parser.h"

int		ft_cd(t_execcmd *cmd, char **env);
int		ft_exit(t_execcmd *cmd);
int		ft_echo(t_execcmd *cmd);
int		ft_pwd(char **args);
int		print(int fd, char *str);

/* `<summary>`:
 Print all name and value pairs of the environment variable.
 `<parameter>`:
 `env`: array of strings containing the env variables;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail. */
t_bool	ft_env(char **env);

/* `<summary>`:
 Removes the corresponding var from the environment variables.
 `<parameter>`:
 `env`: array of strings containing the env variables;
 `var`: the given name to be removed;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail. */
t_bool	ft_unset(t_execcmd *cmd, char **env);

int		ft_export(t_execcmd *cmd, char ***env);

#endif
