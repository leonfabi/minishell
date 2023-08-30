#include "minishell.h"

t_cmd
	*execcmd(void)
{
	t_execcmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	cmd->type = EXECUTE;
	return ((t_cmd *)cmd);
}

t_cmd
	*redircmd(t_cmd *subcmd, t_token *tok, int mode, int fd)
{
	t_redircmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	*cmd = (t_redircmd){
		.type = REDIR,
		.cmd = subcmd,
		.file = tok->value,
		.mode = mode,
		.fd = fd,
	};
	return ((t_cmd *)cmd);
}

t_cmd
	*pipecmd(t_cmd *left, t_cmd *right)
{
	t_pipecmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	*cmd = (t_pipecmd){
		.type = PIPE,
		.left = left,
		.right = right,
	};
	return ((t_cmd *)cmd);
}
