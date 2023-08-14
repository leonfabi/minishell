/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:11:18 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/14 09:27:51 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quotes(char *str)
{
	int	count;
	int	quote_double;
	int	quote_single;

	count = -1;
	quote_double = 0;
	quote_single = 0;
	while (str[++count])
	{
		if (str[count] == 34)
			quote_double++;
		else if (str[count] == 39)
			quote_single++;
		count++;
	}
	if (quote_double % 2 == 0 && quote_single % 2 == 0)
}

t_lexer	*ft_init_lexer(char *str)
{
	t_lexer	*lexer;

	lexer->start = str;
	lexer->counter = str;
	lexer->token_list = NULL;
	return (lexer);
}

t_token	*ft_create_token(t_type type, char *value)
{
	t_token	*token;

	token = (t_token*)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = type;
	token->value = value;
	token->value_length = ft_strlen(token->value);
	return (token);
}

t_token	*lexer(char *str)
{
	t_lexer	*lexer;

	lexer = ft_init_lexer(str);
	while (lexer->counter)
	{
		
	}
}
