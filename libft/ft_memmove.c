/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:31:12 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/17 15:04:02 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dest < src)
	{
		while (i < len)
		{
			((unsigned char*)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dest)[len - 1] = ((const char *)src)[len - 1];
			len--;
		}
	}
	return (dest);
}
