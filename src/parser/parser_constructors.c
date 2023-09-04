#include "minishell.h"

t_cmd	*execcmd(void)
{
	t_execcmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	cmd->type = EXECUTE;
	return ((t_cmd *)cmd);
}

static int	get_correct_fd(t_type type)
{
	if (type == TOKEN_LESS)
		return (0);
	if (type == TOKEN_GREATER)
		return (1);
	if (type == TOKEN_DGREATER)
		return (1);
	return (0);
}

static int	get_correct_mode(t_type type)
{
	if (type == TOKEN_LESS)
		return (O_RDONLY);
	if (type == TOKEN_GREATER)
		return (O_WRONLY | O_TRUNC | O_CREAT);
	if (type == TOKEN_DGREATER)
		return (O_WRONLY | O_CREAT | O_APPEND);
	if (type == TOKEN_DLESS)
		return (O_HEREDOC);
	return (0);
}

t_cmd	*redircmd(t_cmd *subcmd, t_token *tok, char **env)
{
	t_redircmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	*cmd = (t_redircmd){
		.type = REDIR,
		.cmd = subcmd,
		.file = expand_token(tok, env),
		.mode = get_correct_mode(tok->type),
		.fd = get_correct_fd(tok->type),
	};
	return ((t_cmd *)cmd);
}

t_cmd	*pipecmd(t_cmd *left, t_cmd *right)
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
