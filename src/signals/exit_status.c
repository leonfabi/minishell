#include "minishell.h"

int	*get_exit_status(void)
{
	static int	status;

	return (&status);
}

void	set_exit_status(int status)
{
	int		*exit_status;

	exit_status = get_exit_status();
	*exit_status = status;
}
