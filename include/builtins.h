#ifndef BUILTINS_H
# define BUILTINS_H

#include "environment.h"

int	echo(char **arg);
int	pwd(char **args);
int	print(int fd, char *str);
int	env(t_env *env);

t_bool	ft_unset(t_env **env, char *var);

#endif
