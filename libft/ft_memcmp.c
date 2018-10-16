/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:59:22 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/17 14:37:09 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while (((const unsigned char *)s1)[i] == ((const unsigned char *)s2)[i] \
			&& i < n - 1)
		++i;
	return (((const unsigned char *)s1)[i] - ((const unsigned char *)s2)[i]);
}
