/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:39:10 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/14 17:29:42 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <stdlib.h>

const char* t_type_strings[] = {
    "TOKEN_WORD",
    "TOKEN_FLAG",
    "TOKEN_PIPE",
    "TOKEN_LESS",
    "TOKEN_GREATER",
    "TOKEN_DLESS",
    "TOKEN_DGREATER",
    "TOKEN_EOF",
    "TOKEN_QUOTE",
    "TOKEN_DQUOTE",
    "TOKEN_NEWLINE"
};

void	ft_print_token_list(t_lexer *lexer)
{
	int		len;
	int		count;
	t_type	type;

	len = 0;
	while(lexer->token_list != NULL)
	{
		count = 0;
		type = ((t_token *)lexer->token_list->content)->type;
		len = ((t_token *)lexer->token_list->content)->value_length;
		printf("TOKEN: %s\t", t_type_strings[type]);
		while (len > count)
		{
			printf("%c", ((t_token *)lexer->token_list->content)->value[count]);
			count++;
		}
		printf("\n-----------------------\n");
		lexer->token_list = lexer->token_list->next;
	}
}

int	main(void)
{
	// char	str[] = "''a''";
	char	*str;

	// int		i;
	t_lexer	lexer;

	// i = -1;
	str = readline(" > ");
	// printf("%s\n", str);
	// while (str[++i])
	// 	printf("str[%d] = %c\n", i, str[i]);
	lexer = ft_lexer(str);
	ft_print_token_list(&lexer);
	// return (0);
	// free(str);
	return (0);
}