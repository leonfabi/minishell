/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:50:07 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:50:08 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "utils.h"

/* `<SUMMARY>`:
 * Function for cleaning an execution command. An execution
 * node is always the last node in a branch of the AST and
 * therefore does not call the `clean_ast` function again.
 * `<PARAM>`:
 * `cmd`: execution node of the AST;
 * `<RETURN>`:
 * NOTHING. */
static void	clean_ecmd(t_cmd *cmd)
{
	t_execcmd	*ecmd;
	char		**args;

	ecmd = (t_execcmd *)cmd;
	free(ecmd->bin);
	args = ecmd->argv;
	while (NULL != *args)
	{
		free(*args);
		++args;
	}
	free(ecmd);
}

/* `<SUMMARY>`:
 * Function for cleaning a redirect command. It calls the `clean_ast`
 * function again for the subcmd of the redirect node.
 * `<PARAM>`:
 * `cmd`: redirect node of the AST;
 * `<RETURN>`:
 * NOTHING. */
static void	clean_rcmd(t_cmd *cmd)
{
	t_redircmd	*rcmd;

	rcmd = (t_redircmd *)cmd;
	clean_ast(rcmd->cmd);
	free(rcmd->file);
	rcmd->file = NULL;
	free(rcmd);
}

/* `<SUMMARY>`:
 * Function for cleaning a pipe command. It recursively calls the
 * `clean_ast` command of the left and right branch of the pipe node.
 * Subsequently frees the pipe node.
 * `<PARAM>`:
 * `cmd`: pipe node of the AST;
 * `<RETURN>`:
 * NOTHING. */
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
