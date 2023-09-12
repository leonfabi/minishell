#include "minishell.h"

int	get_correct_fd(t_type type)
{
	if (type == TOKEN_LESS)
		return (STDIN_FILENO);
	if (type & (TOKEN_GREATER | TOKEN_DGREATER))
		return (STDOUT_FILENO);
	return (0); // NOTE: think about common return type
}

int	get_correct_mode(t_type type)
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

// void	print_redir(t_cmd *cmd)
// {
// 	if (cmd->type != REDIR)
// 		printf("Not the expected type\n");
// 	else
// 	{
// 		printf("Node: %p, rcmd file: %s, redir points to: %p\n", cmd, ((t_redircmd *)cmd)->file, ((t_redircmd *)cmd)->cmd);
// 	}
// }

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
