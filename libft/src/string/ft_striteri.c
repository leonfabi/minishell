/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:05:11 by makurz            #+#    #+#             */
/*   Updated: 2023/04/18 22:24:08 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function 'f' to all characters in string 's'.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!f || !s)
		return ;
	i = -1;
	while (s[++i])
		(*f)(i, &s[i]);
}
