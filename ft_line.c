/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/05/18 15:37:41 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_line_signed(t_stringinfo *t, int i)
{
	if((t->len = ft_strlen(ft_longtoa((long int)nbr))) < t->sizemin)
		t->len = t->sizemin;
	t->line = ft_strnew(t->len);
	if 

}

void	ft_line_unsigned(t_stringinfo *t, int i)
{
	int i = 0;
	int j = 0;
	char *str;

	str = ft_strdup(ft_sizetoa((size_t)nbr));
	if((t->len = ft_strlen(str)) < t->sizemin)
		t->len = t->sizemin;
	t->line = ft_strnew(t->len);
	i = (t->aligne) ? 0 : ft_strlen(str);
	while (j < i)
	{
		if (t->zeros)
			t->line[j] = '0';
		else
			t->line[j] = ' ';
		j++;
	}
	if (t->space || t->sign)
		t->line[j] = (t->space) ? ' ' : '+';
	j++;
	i = 0;
	while (str[i])
	{
		t->line[j] = str[i];
		i++;
		j++:
	}
}