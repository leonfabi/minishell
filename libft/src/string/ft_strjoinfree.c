/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:11:03 by makurz            #+#    #+#             */
/*   Updated: 2023/09/08 16:20:28 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// joins 2 strings together and frees the memory of the string
// given by the 'control' character.
char	*ft_strjoinfree(char *s1, char *s2, char control)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (control == 'L' || control == 'B')
		free(s1);
	if (control == 'R' || control == 'B')
		free(s2);
	return (new);
}
