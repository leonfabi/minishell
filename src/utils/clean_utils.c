#include "minishell.h"

void	adv_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

