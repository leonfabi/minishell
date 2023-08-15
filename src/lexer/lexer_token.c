/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:19:47 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/15 14:54:13 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_make_append_token(t_lexer *lexer, t_type type)
{
	t_token	*token;

	token = ft_create_token(type, lexer);
	if (token == NULL)
		return (FALSE);
	if (ft_dlstadd_back(&lexer->token_list, ft_dlstnew(token)) == FALSE)
		return (FALSE);
	if (type == TOKEN_EOF || type == TOKEN_WORD)
		return (lexer->start = lexer->counter, TRUE);
	lexer->counter++;
	lexer->start = lexer->counter;
	return (TRUE);
}

int	ft_quoted_token(t_lexer *lexer)
{
	char	quote;

	quote = 34;
	if (*lexer->counter == 39)
		quote = 39;
	// while (ft_is_section(*lexer->counter) == FALSE)
	// 	lexer->counter++;
	lexer->counter++;
	while (*lexer->counter != quote && *lexer->counter != '\0')
		lexer->counter++;
	if (*lexer->counter == '\0')
		return (error_msg("Quotes format error"), FALSE);
	if (quote == 34)
	{
		if (ft_make_append_token(lexer, TOKEN_DQUOTE) == FALSE)
			return (FALSE);
	}
	else if (ft_make_append_token(lexer, TOKEN_QUOTE) == FALSE)
		return (FALSE);
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
				return (FALSE);
		}
		else if (ft_make_append_token(lexer, TOKEN_LESS) == FALSE)
			return (FALSE);
	}
	else if (*lexer->counter == '>')
	{
		if (*(lexer->counter + 1) == '>')
		{
			lexer->counter++;
			if (ft_make_append_token(lexer, TOKEN_DGREATER) == FALSE)
				return (FALSE);
		}
		else if (ft_make_append_token(lexer, TOKEN_GREATER) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	ft_word_token(t_lexer *lexer)
{
	while (ft_is_section(*lexer->counter) == FALSE && \
	ft_isspace(*lexer->counter) == FALSE)
		lexer->counter++;
	if (ft_make_append_token(lexer, TOKEN_WORD) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_find_more_token(t_lexer *lexer)
{
	if (*lexer->counter == '\n' && \
	ft_make_append_token(lexer, TOKEN_NEWLINE) == FALSE)
		return (FALSE);
	lexer->counter++;
	return (TRUE);
}

int	ft_find_token(t_lexer *lexer)
{

	while (*lexer->counter != '\0')
	{
		printf("CURR CHAR: %c\n", *lexer->counter);
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
				return (FALSE);
		}
		else if (ft_word_token(lexer) == FALSE)
			return (FALSE);
	}
	if (*lexer->counter == '\0' && \
	ft_make_append_token(lexer, TOKEN_EOF) == FALSE)
		return (FALSE);
	return (TRUE);
}
