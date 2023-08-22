/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:31:46 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/21 15:44:17 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/header/libft.h"
# include "defines.h"
# include "environment.h"
# include "signal_handler.h"
# include "lexer.h"
# include "builtins.h"

typedef struct s_main
{
	char		*user;
	t_env		env;
	t_path		bin_path;
	t_bool		no_environment;
	t_lexer		lexer;
	t_termios	xterm;
}	t_main;

#endif