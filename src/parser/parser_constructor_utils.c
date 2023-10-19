/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_constructor_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:46:05 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/19 11:46:06 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "parser.h"

int	*get_expand(void)
{
	static int	expand;

	return (&expand);
}

void	set_expand(int state)
{
	int		*expand;

	expand = get_expand();
	*expand = state;
}

int	get_correct_fd(t_type type)
{
	if (type == TOKEN_LESS)
		return (STDIN_FILENO);
	if (type & (TOKEN_GREATER | TOKEN_DGREATER))
		return (STDOUT_FILENO);
	return (-1);
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
