/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:37:38 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/16 14:37:43 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		r;
	char	*new;

	i = 0;
	r = 0;
	if (!s)
		return (ft_strdup(""));
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	if (i == j + 1)
		return (ft_strdup(""));
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= 0)
		--j;
	if (!(new = (char *)malloc(j - i + 2)))
		return (NULL);
	while (i <= j)
		new[r++] = s[i++];
	new[r] = '\0';
	return (new);
}
