/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:11:18 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/14 14:31:22 by fkrug            ###   ########.fr       */
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
		return (0);
	return (1);
}

t_lexer	ft_init_lexer(char *str)
{
	t_lexer	lexer;

	lexer = (t_lexer){
		.start = str,
		.counter = str,
		.token_list = NULL
	};
	return (lexer);
}

t_token	*ft_create_token(t_type type, t_lexer *lexer)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = type;
	token->value = lexer->start;
	token->value_length = lexer->counter - lexer->start;
	return (token);
}

t_lexer	ft_lexer(char *str)
{
	t_lexer	lexer;

	if (ft_check_quotes(str))
		return ((t_token *) NULL);
	lexer = ft_init_lexer(str);

	return (NULL);
}
