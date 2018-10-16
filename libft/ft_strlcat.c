/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:07:40 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/17 14:45:32 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] && i < size)
		++i;
	len = i;
	while (i < size - 1 && src[i - len])
	{
		dest[i] = src[i - len];
		++i;
	}
	if (len < size)
		dest[i] = '\0';
	return (ft_strlen(src) + len);
}
