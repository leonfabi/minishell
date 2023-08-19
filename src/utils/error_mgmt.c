/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:49:02 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/17 11:28:50 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_handler(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	ft_dlstclear(&(lexer->token_list), &free);
}

void	error_msg(t_lexer *lexer, char *str)
{
	printf("Error: %s\n", str);
	error_handler(lexer);
}
