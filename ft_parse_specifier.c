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

void	ft_line_char(t_stringinfo *t)
{
	int len;
//	ft_putstr("passe par print\n");

	len = ft_size_base((size_t)t->unbr, base);
	if (t->space && t->precision > t->sizemin)
		t->len = 1;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
	if (!t->aligne_g)
	{
		if(t->prefixe)
			t->sizemin--;
		if(t->prefixe && base == 16)
			t->sizemin--;
		while (t->sizemin-- > 0)
		{
			if(t->zeros)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	ft_prefix(t, base, maj);
	while (t->precision-- > 0)
		ft_putchar('0');
	ft_putnbr_base(t->unbr, base, maj, 0);
	if (t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
	t->ret += t->len;
}

void	ft_char(t_stringinfo *t)
{
	if (*t->str != 'c' && *t->str != 'C')
		t->unbr = *t->str;
	else if (t->conversion == 3 || *t->str == 'C')
		t->unbr = (unsigned int)va_arg(t->ap, unsigned int);
	else if (*t->str == 'c')
		t->unbr = (unsigned int)va_arg(t->ap, unsigned int);
	ft_line_char(t);
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
