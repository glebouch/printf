/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:23:37 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/10 15:53:15 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)(str));
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			++j;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
		}
		++i;
	}
	return (0);
}
