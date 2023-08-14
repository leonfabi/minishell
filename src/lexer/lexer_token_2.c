/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:01 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/14 18:12:38 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_section(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '\n' || c == '\0' || c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}

void	ft_skip_whitespace(t_lexer *lexer)
{
	while (ft_isspace(*lexer->counter) == TRUE && *lexer->counter != '\0')
		lexer->counter++;
	lexer->start = lexer->counter;
}
