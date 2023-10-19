/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:51:25 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:51:26 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "signals.h"
#include "utils.h"

int	ft_env(t_execcmd *cmd)
{
	char	**run;

	if (cmd->argv[1] != NULL)
	{
		general_error(cmd->argv[1], "No such file or directory", NULL);
		set_exit_status(127);
		return (127);
	}
	run = cmd->sh->env;
	while (*run != NULL)
	{
		printf("%s\n", *run);
		++run;
	}
	set_exit_status(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
