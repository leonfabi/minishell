#include "libft.h"
#include "defines.h"

void	adv_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

pid_t	adv_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_fprintf(2, "ERROR");
	return (pid);
}
