/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:51:41 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:51:42 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "environment.h"
#include "signals.h"

/* `<SUMMARY>`:
 * .Function to unset the given `key` from the environment array
 * of strings.
 * `<PARAM>`:
 * `sh`: main struct containing also the environment;
 * `name`: variable to remove from the environment;
 * `<RETURN>`:
 * False if environment length is 0, `TRUE` after removing the
 * given key=value pairs. */
static t_bool	run_unset(t_main *sh, char *name)
{
	char	**delete;
	char	**shift;
	size_t	len;

	len = ft_arrlen((const char **)sh->env);
	if (0 == len)
		return (FALSE);
	delete = sh->env;
	while (NULL != *delete)
	{
		if (check_env_variable(*delete, name) == TRUE)
			break ;
		++delete;
	}
	shift = delete;
	free(*delete);
	while (shift < sh->env + len)
	{
		*shift = *(shift + 1);
		++shift;
	}
	*shift = NULL;
	return (TRUE);
}

int	ft_unset(t_execcmd *cmd)
{
	int		i;

	i = 0;
	set_exit_status(EXIT_SUCCESS);
	if (NULL == cmd->argv[1])
		return (EXIT_SUCCESS);
	while (NULL != cmd->argv[++i])
	{
		run_unset(cmd->sh, cmd->argv[i]);
		if (ft_strcmp("PATH", cmd->argv[i]) == 0)
		{
			cmd->sh->bin_path = update_bin_path(cmd->sh, NULL);
		}
	}
	return (EXIT_SUCCESS);
}
