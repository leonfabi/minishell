/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:51:39 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:51:39 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "utils.h"
#include "signals.h"

int	ft_pwd(t_execcmd *cmd)
{
	char	buffer[PATH_MAX];

	if (cmd->argv[1] != NULL)
	{
		general_error("pwd", ERR_ARG, NULL);
		set_exit_status(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	if (getcwd(buffer, PATH_MAX) == NULL)
	{
		set_exit_status(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	printf("%s\n", buffer);
	set_exit_status(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
