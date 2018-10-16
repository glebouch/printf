/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:04:05 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/14 11:18:05 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
