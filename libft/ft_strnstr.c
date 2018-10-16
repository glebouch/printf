/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:56:29 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/16 15:05:35 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)(str));
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && j + i < len)
		{
			if (to_find[j + 1] == '\0' && j + i < len)
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
