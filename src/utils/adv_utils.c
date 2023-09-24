#include "libft.h"
#include "defines.h"
#include "utils.h"

void	adv_free(char **to_free)
{
	if (NULL == to_free)
		return ;
	free(*to_free);
	*to_free = NULL;
}

pid_t	adv_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		general_error("forking", "could not fork the process", NULL);
	return (pid);
}
