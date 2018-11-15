/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:18:51 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_char2(t_stringinfo *t)
{
	int oct;

//	ft_putendl("toto\n");
	oct = ft_octet(t->ch);
	t->sizemin = (t->sizemin > oct) ? t->sizemin - oct : 0;
	t->len += t->sizemin + oct;
	if (!t->aligne_g)
	{
		while (t->sizemin-- > 0)
		{
			if(t->zeros)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	if (t->ch < 127)
		ft_putchar((char)t->ch);
	else
		ft_putchar_unicode(t->ch, oct);
	if (t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
	t->ret += t->len;
}

void	ft_char(t_stringinfo *t)
{
//	ft_putendl("totoro");
	if (*t->str != 'c' && *t->str != 'C')
		t->ch = *t->str;
	else if (t->conversion == 3 || *t->str == 'C')
		t->ch = (wchar_t)va_arg(t->ap, unsigned int);
	else if (*t->str == 'c')
		t->ch = (char)va_arg(t->ap, unsigned int);
	ft_char2(t);
}