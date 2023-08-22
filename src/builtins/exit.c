/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:45:56 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/21 15:59:23 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit(char **args)
{
	cmd = exit;

	cmd == "exit" => TRUE
	=> exit routine (free all, cleanup + exit);

	exit(0);

	// Send SIGINT signal
}
