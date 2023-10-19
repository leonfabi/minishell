/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:50:51 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:50:52 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*get_close_fd(void)
{
	static int	fd;

	return (&fd);
}

void	set_close_fd(int set_fd)
{
	int		*fd;

	fd = get_close_fd();
	*fd = set_fd;
}
