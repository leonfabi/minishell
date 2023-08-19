/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:01 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/17 10:44:27 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_more_token(t_lexer *lexer)
{
	if (*lexer->counter == '\n' && \
	ft_make_append_token(lexer, TOKEN_NEWLINE) == FALSE)
		return (FALSE);
	lexer->counter++;
	return (TRUE);
}

int	ft_make_append_token(t_lexer *lexer, t_type type)
{
	t_token	*token;

	token = ft_create_token(type, lexer);
	if (token == NULL)
		return (error_msg("Creating token failed"), FALSE);
	if (ft_dlstadd_back(&lexer->token_list, ft_dlstnew(token)) == FALSE)
		return (error_msg("Appending token failed"), FALSE);
	if (type == TOKEN_EOF || type == TOKEN_WORD)
		return (lexer->start = lexer->counter, TRUE);
	lexer->counter++;
	lexer->start = lexer->counter;
	return (TRUE);
}

int	ft_is_section(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '\n' || \
	c == '\0' || c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}

void	ft_skip_whitespace(t_lexer *lexer)
{
	while (ft_isspace(*lexer->counter) == TRUE && *lexer->counter != '\0')
		lexer->counter++;
	lexer->start = lexer->counter;
}
