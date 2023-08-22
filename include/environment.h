#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "defines.h"

typedef struct s_env	t_env;

struct s_env
{
	t_env	*next;
	char	*name;
	char	*value;
};

#endif