/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:39:10 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/09 17:03:15 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../include/minishell.h"
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
	free(str);
	return (0);
}