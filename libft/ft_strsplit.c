/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:54:16 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/16 14:49:06 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	if (!(*str))
		return (0);
	while (*str == c)
		str++;
	while (*str != c && *str)
		str++;
	if (*(str - 1) == c && !(*str))
		return (0);
	return (1 + ft_count_words(str, c));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tot;
	int		countw;
	int		i;
	int		j;

	i = -1;
	if (!s)
		return (NULL);
	countw = ft_count_words(s, c);
	if (!(tot = (char **)malloc(sizeof(char*) * (countw + 1))))
		return (NULL);
	while (++i < countw)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c && s[j])
			j++;
		if (!(tot[i] = ft_strnew(j)))
			return (NULL);
		ft_strncpy(tot[i], s, j);
		s = s + j;
	}
	tot[countw] = NULL;
	return (tot);
}
