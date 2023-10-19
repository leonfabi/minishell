/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:55:14 by makurz            #+#    #+#             */
/*   Updated: 2023/06/01 14:45:43 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *str, char c)
{
	int		count;
	char	**arr;
	int		i;

	i = 0;
	count = ft_count_words(str, c);
	arr = ft_calloc(sizeof(char *), (count + 1));
	if (arr == NULL)
		return (NULL);
	arr[count] = NULL;
	while (i < count)
	{
		if (*str == c)
			str++;
		else
		{
			arr[i] = ft_substr(str, 0, ft_strlen_c(str, c));
			if (arr[i] == NULL)
				return (ft_arrfree(arr), NULL);
			str += ft_strlen_c(str, c);
			++i;
		}
	}
	return (arr);
}
