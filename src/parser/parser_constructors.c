#include "minishell.h"

t_cmd	*execcmd(t_main *sh)
{
	t_execcmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	*cmd = (t_execcmd){
		.type = EXECUTE,
		.bin = NULL,
		.sh = sh
	};
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

// t_cmd	*redircmd(t_cmd *subcmd, t_token *tok, t_token *file, char **env)
// {
// 	t_redircmd	*cmd;

// 	cmd = ft_calloc(1, sizeof(*cmd));
// 	if (NULL == cmd)
// 		return (NULL);
// 	*cmd = (t_redircmd){
// 		.type = REDIR,
// 		.cmd = subcmd,
// 		.file = expand_token(file, env),
// 		.mode = get_correct_mode(tok->type),
// 		.fd = get_correct_fd(tok->type),
// 		.expand = (tok->type & ~(TOKEN_QUOTE)) && (tok->type & ~(TOKEN_DQUOTE))
// 	};
// 	return ((t_cmd *)cmd);
// }

void	print_redir(t_cmd *cmd)
{
	if (cmd->type != REDIR)
		printf("Not the expected type\n");
	else
	{
		printf("Node: %p, rcmd file: %s, redir points to: %p\n", cmd, ((t_redircmd *)cmd)->file, ((t_redircmd *)cmd)->cmd);
	}
}

t_cmd	*adjust_redir(t_cmd *subcmd, t_redircmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*prev;

	prev = subcmd;
	tmp = subcmd;
	while (tmp->type != EXECUTE)
	{
		prev = tmp;
		tmp = ((t_redircmd *)tmp)->cmd;
	}
	cmd->cmd = tmp;
	((t_redircmd *)prev)->cmd = (t_cmd *)cmd;
	return ((t_cmd *)subcmd);
}

t_cmd	*redircmd(t_cmd *subcmd, t_token *tok, t_token *file, char **env)
{
	t_redircmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	*cmd = (t_redircmd){
		.type = REDIR,
		.cmd = subcmd,
		.file = expand_token(file, env),
		.mode = get_correct_mode(tok->type),
		.fd = get_correct_fd(tok->type),
		.expand = (tok->type & ~(TOKEN_QUOTE)) && (tok->type & ~(TOKEN_DQUOTE))
	};
	if (subcmd->type == REDIR)
		return (adjust_redir(subcmd, cmd));
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
