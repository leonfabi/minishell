#include "minishell.h"

void	clean_ast(t_cmd *cmd);

static void	clean_ecmd(t_cmd *cmd)
{
	t_execcmd	*ecmd;
	char		**args;

	ecmd = (t_execcmd *)cmd;
	args = ecmd->argv;
	while (NULL != *args)
	{
		free(*args);
		++args;
	}
	free(ecmd);
}

static void	clean_rcmd(t_cmd *cmd)
{
	t_redircmd	*rcmd;

	rcmd = (t_redircmd *)cmd;
	clean_ast(rcmd->cmd);
	free(rcmd->file);
	rcmd->file = NULL;
	free(rcmd);
}

static void	clean_pcmd(t_cmd *cmd)
{
	t_pipecmd	*pcmd;

	pcmd = (t_pipecmd *)cmd;
	clean_ast(pcmd->left);
	clean_ast(pcmd->right);
	free(pcmd);
}

void	clean_ast(t_cmd *cmd)
{

	if (NULL == cmd)
		return ;
	if (cmd->type == EXECUTE)
		return (clean_ecmd(cmd));
	else if (cmd->type == REDIR)
		return (clean_rcmd(cmd));
	return (clean_pcmd(cmd));
}
