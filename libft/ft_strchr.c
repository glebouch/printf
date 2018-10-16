/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:15:04 by glebouch          #+#    #+#             */
/*   Updated: 2017/12/15 13:38:52 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != c && str[i])
	{
		++i;
		if (str[i] == '\0')
			return (NULL);
	}
	return ((char *)(str + i));
}
