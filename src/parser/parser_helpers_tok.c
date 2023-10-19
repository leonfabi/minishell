/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers_tok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:46:12 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/19 11:46:13 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "parser.h"

t_type	get_token_type(t_dlist *token)
{
	t_token		*tok;

	if (NULL == token)
		return (TOKEN_EOF);
	tok = (t_token *)token->content;
	return (tok->type);
}

t_token	*get_token(t_dlist *token)
{
	if (NULL == token)
		return (NULL);
	return ((t_token *)token->content);
}
