/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:19:47 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/19 17:32:28 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quoted_token(t_lexer *lexer)
{
	char	quote;

	quote = 34;
	if (*lexer->counter == 39)
		quote = 39;
	lexer->counter++;
	while (*lexer->counter != quote && *lexer->counter != '\0')
		lexer->counter++;
	if (*lexer->counter == '\0')
		return (error_msg(lexer, "Quotes format error"), FALSE);
	if (quote == 34)
	{
		if (ft_make_append_token(lexer, TOKEN_DQUOTE) == FALSE)
			return (error_msg(lexer, "DQUOTEtoken failed"), FALSE);
	}
	else if (ft_make_append_token(lexer, TOKEN_QUOTE) == FALSE)
		return (error_msg(lexer, "QUOTE token failed"), FALSE);
	return (TRUE);
}

int	ft_redirect_token(t_lexer *lexer)
{
	if (*lexer->counter == '<')
	{
		if (*(lexer->counter + 1) == '<')
		{
			lexer->counter++;
			if (ft_make_append_token(lexer, TOKEN_DLESS) == FALSE)
				return (error_msg(lexer, "DLESS token failed"), FALSE);
		}
		else if (ft_make_append_token(lexer, TOKEN_LESS) == FALSE)
			return (error_msg(lexer, "LESS token failed"), FALSE);
	}
	else if (*lexer->counter == '>')
	{
		if (*(lexer->counter + 1) == '>')
		{
			lexer->counter++;
			if (ft_make_append_token(lexer, TOKEN_DGREATER) == FALSE)
				return (error_msg(lexer, "DGREATER token failed"), FALSE);
		}
		else if (ft_make_append_token(lexer, TOKEN_GREATER) == FALSE)
			return (error_msg(lexer, "GREATER token failed"), FALSE);
	}
	return (TRUE);
}

int	ft_word_token(t_lexer *lexer)
{
	while (ft_is_section(*lexer->counter) == FALSE && \
	ft_isspace(*lexer->counter) == FALSE)
		lexer->counter++;
	if (ft_make_append_token(lexer, TOKEN_WORD) == FALSE)
		return (error_msg(lexer, "WORD token failed"), FALSE);
	return (TRUE);
}

int	ft_identify_token(t_lexer *lexer)
{
	while (*lexer->counter != '\0')
	{
		if (*lexer->counter == 34 || *lexer->counter == 39)
		{
			if (ft_quoted_token(lexer) == FALSE)
				return (FALSE);
		}
		else if (ft_isspace(*lexer->counter) == TRUE)
			ft_skip_whitespace(lexer);
		else if (*lexer->counter == '<' || *lexer->counter == '>')
		{
			if (ft_redirect_token(lexer) == FALSE)
				return (FALSE);
		}
		else if (*lexer->counter == '|')
		{
			if (ft_make_append_token(lexer, TOKEN_PIPE) == FALSE)
				return (error_msg(lexer, "PIPE token failed"), FALSE);
		}
		else if (ft_word_token(lexer) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	ft_find_token(t_lexer *lexer)
{
	if (ft_identify_token(lexer) == FALSE)
		return (FALSE);
	if (*lexer->counter == '\0' && \
	ft_make_append_token(lexer, TOKEN_EOF) == FALSE)
		return (error_msg(lexer, "EOF token failed"), FALSE);
	return (TRUE);
}
