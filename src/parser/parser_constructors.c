/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:46:09 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/19 11:46:10 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "parser.h"

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

t_cmd	*redircmd(t_cmd *subcmd, t_token *tok, t_dlist **file, char **env)
{
	t_redircmd	*cmd;

	if (get_token_type(*file) & TOKEN_WORD)
		set_expand(TRUE);
	else if (get_token_type(*file) & (TOKEN_QUOTE | TOKEN_DQUOTE))
		set_expand(FALSE);
	cmd = ft_calloc(1, sizeof(*cmd));
	if (NULL == cmd)
		return (NULL);
	*cmd = (t_redircmd){
		.type = REDIR,
		.cmd = subcmd,
		.expand = *get_expand(),
		.mode = get_correct_mode(tok->type),
		.fd = get_correct_fd(tok->type)
	};
	cmd->file = connect_tokens(file, env);
	if (*get_expand() == FALSE)
		cmd->expand = FALSE;
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
