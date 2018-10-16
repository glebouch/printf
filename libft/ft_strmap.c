/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:59:44 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/14 11:17:30 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		new[i] = f(s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
