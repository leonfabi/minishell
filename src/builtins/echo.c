/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:09:29 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/21 13:18:29 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **arg)
{
	int	count;
	int	new_line;
	int	print;

	count = 0;
	print = 0;
	new_line = 1;
	if (arg[0] == NULL)
		return (printf("\n"), TRUE);
	if (!ft_strcmp(arg[0],"-n"))
	{
		new_line = 0;
		count++;
	}
	while (arg[count])
	{
		if (print)
			printf(" ");
		printf("%s", arg[count]);
		print++;
		count++;
	}
	if (new_line)
		printf("\n");
	return (TRUE);
}
