/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/05/18 15:37:41 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
** %[specifier] == d, i, o, u, x, X, c, s, C, S, p, D, O, U;
**
*/



void	ft_str(t_stringinfo *t)
{
	t->string = va_arg(t->ap, wchar_t *);
	while(*t->string++ != '\0')
	{
		ft_putstr((char*)t->string);
	}
}

void	ft_char(t_stringinfo *t)
{
//	wchar_t ch;
	if (*t->str != 'c' && *t->str != 'C')
		t->ch = *t->str;
	else if (t->conversion == 3 || *t->str == 'C')
		t->ch = (wchar_t)va_arg(t->ap, int);
	else if (*t->str == 'c')
		t->ch = (char)va_arg(t->ap, int);
}

void ft_parse_specifier(t_stringinfo *t)
{
//	ft_putstr("tototo\n");
	if (ft_strchr("Ddi", *t->str))
		ft_signed(t);
	else if (ft_strchr("oOuUxXp", *t->str))
		ft_unsigned(t);
	else if (*t->str == 's' || *t->str == 'S')
		ft_str(t);
	else
		ft_char(t);
}

//OUp -> ne peut pas etre converti


//ouxX -> peut etre converti
