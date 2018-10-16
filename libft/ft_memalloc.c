/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:06:42 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/13 16:25:00 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (!(tab = (void *)malloc(size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
}
