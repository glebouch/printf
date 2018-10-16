/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:28:35 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/13 16:25:57 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	while (size != 0)
	{
		str[size] = '\0';
		size--;
	}
	str[0] = '\0';
	return (str);
}
