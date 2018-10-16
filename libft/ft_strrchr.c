/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:38:08 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/10 18:44:59 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	if (c == 0)
		return ((char *)(str + len));
	while (str[len - i] != c)
	{
		if (len - i == 0)
			return (NULL);
		++i;
	}
	return ((char *)(str + len - i));
}
