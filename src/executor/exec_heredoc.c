#include "libft.h"
#include "defines.h"
#include "executor.h"
#include "expander.h"

void	execute_heredoc(t_redircmd *redir, t_context *ctx)
{
	char	*input;
	char	*delim;

	input = readline("> ");
	delim = redir->file;
	while (input && (ft_strcmp(input, delim) != 0))
	{
		if (redir->expand == TRUE)
			input = 
	}
}
