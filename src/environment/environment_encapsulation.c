/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_encapsulation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:51:10 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:51:10 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "utils.h"

char	***get_env_arr(void)
{
	static char	**env;

	return (&env);
}

void	set_env_arr(char **env)
{
	char	***env_arr;

	env_arr = get_env_arr();
	*env_arr = env;
}

char	***get_bin_path(void)
{
	static char	**bin;

	return (&bin);
}

void	set_bin_path(char **bin)
{
	char	***bin_path;

	bin_path = get_bin_path();
	*bin_path = bin;
}
