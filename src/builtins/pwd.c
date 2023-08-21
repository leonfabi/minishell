/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:23:01 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/21 13:36:04 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(char **args)
{
	char	buffer[1024];

	if (args != NULL && args[0] != NULL)
		return (printf("pwd: too many arguments\n"), FALSE);
	if (getcwd(buffer, (size_t)1024) == NULL)
		return (FALSE);
	printf("%s\n", buffer);
	return (TRUE);
}
