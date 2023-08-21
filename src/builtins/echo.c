/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:09:29 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/21 15:26:50 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **arg)
{
	int		count;
	t_bool	new_line;
	t_bool	print;

	count = 0;
	print = FALSE;
	new_line = TRUE;
	if (arg[0] == NULL)
		return (printf("\n"), TRUE);
	if (ft_strcmp(arg[0],"-n") == 0)
	{
		new_line = FALSE;
		count++;
	}
	while (arg[count] != NULL)
	{
		if (print == TRUE)
			printf(" ");
		printf("%s", arg[count]);
		print = TRUE;
		count++;
	}
	if (new_line == TRUE)
		printf("\n");
	return (TRUE);
}
