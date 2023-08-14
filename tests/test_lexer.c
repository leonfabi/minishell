/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:39:10 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/14 10:42:08 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <stdlib.h>

int	main(void)
{
	char	*str;
	int		i;

	i = -1;
	str = readline(">");
	printf("%s\n", str);
	while (str[++i])
		printf("str[%d] = %c\n", i, str[i]);
	ft_lexer(str);
	free(str);
	return (0);
}