/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:11:18 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/09 17:25:05 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_init_token_list(char *str)
{
	t_dlist	*token_list;

	
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
	
}
