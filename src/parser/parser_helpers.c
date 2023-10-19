/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:46:18 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/19 11:46:19 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "parser.h"

t_bool	check_tok_connection(t_token *tok)
{
	if (tok->type & TOKEN_WORD & (ft_isspace(*(tok->value + tok->len)) == 0))
		return (TRUE);
	else if (tok->type & (TOKEN_DQUOTE | TOKEN_QUOTE))
	{
		if (ft_isspace(*(tok->value + tok->len + 1)) == 0)
		{
			set_expand(FALSE);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	check_redirect(t_type type)
{
	if (type & (TOKEN_LESS | TOKEN_DLESS))
		return (TRUE);
	if (type & (TOKEN_GREATER | TOKEN_DGREATER))
		return (TRUE);
	return (FALSE);
}

t_bool	check_arguments(t_type type)
{
	if (type & (TOKEN_WORD | TOKEN_QUOTE | TOKEN_DQUOTE))
		return (TRUE);
	return (FALSE);
}

t_bool	check_metachars(t_type type)
{
	if (type == TOKEN_PIPE)
		return (TRUE);
	return (FALSE);
}

t_cmd	*select_redirect(t_cmd *subcmd, t_dlist **list, char **env)
{
	t_token		*redir;

	redir = get_token(*list);
	*list = (*list)->next;
	if (redir->type == TOKEN_LESS)
		return (redircmd(subcmd, redir, list, env));
	if (redir->type == TOKEN_GREATER)
		return (redircmd(subcmd, redir, list, env));
	if (redir->type == TOKEN_DGREATER)
		return (redircmd(subcmd, redir, list, env));
	if (redir->type == TOKEN_DLESS)
		return (redircmd(subcmd, redir, list, env));
	return (NULL);
}
