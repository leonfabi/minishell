#include "minishell.h"

int	pwd(char **args)
{
	char	buffer[PATH_MAX];

	if (args != NULL && args[0] != NULL)
		return (printf("pwd: too many arguments\n"), FALSE);
	if (getcwd(buffer, PATH_MAX) == NULL)
		return (FALSE);
	printf("%s\n", buffer);
	return (TRUE);
}
