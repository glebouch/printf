/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:00 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 19:05:36 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
** %[flags] == #, 0, -, ' ', +;
**
*/

void	ft_flags_conversion(t_stringinfo *t)
{
	int conv = 0;
	if (*t->str == 'h')
	{
		if (t->str[1] == 'h')
			conv = 1;
		else
			conv = 2;
	}
	else if (*t->str == 'l')
	{
		if (t->str[1] == 'l')
			conv = 4;
		else
			conv = 3;
	}
	else if (*t->str == 'j')
		conv = 5;
	else if (*t->str == 'z')
		conv = 6;
	t->conversion = (conv > t->conversion) ? conv : t->conversion;
	t->str += (conv == 1 || conv == 4) ? 1 : 0;
}

void	ft_flags_ponct(t_stringinfo *t)
{
//	ft_putstr("passe par ponctuation\n");
	if (*t->str == '-')
	{
		t->aligne_g = 1;
//		t->zeros = (t->zeros > 0) ? -1 : 0;
		t->zeros = 0;
	}
	else if (*t->str == '+')
	{
		t->sign = 1;
		t->space = 0;
	}
	else if (*t->str == ' ' && t->sign == 0)
		t->space = 1;
	else if (*t->str == '.')
	{
		t->str += (ft_isdigit(*(t->str + 1)) != 0) ? 1 : 0;
		t->precision = ft_atoi(t->str);
//		t->zeros = (t->zeros > 0) ? -1 : 0;
		t->zeros = 0;
//		ft_putstr(t->str);
		if(ft_atoi(t->str))
			t->str += ft_strlen(ft_itoa(ft_atoi(t->str))) - 1;
//		if (t->precision)
//			t->str += ft_strlen(ft_itoa(t->precision)) - 1;
//		ft_putchar('\n');
//		ft_putstr(t->str);
	}
//	ft_putendl("fini ponct");
}

/*
printf("%0.0d", 42)
printf("%0.d", 42)
printf("%0.1d", 42)
*/

void	ft_parse_flags(t_stringinfo *t)
{
// 	ft_putstr(t->str);
	while (*t->str && ft_strchr("-+0 #.hljz123456789", *t->str))
	{
//		ft_putstr(t->str);
//		ft_putendl("coucou");
//	ft_putchar(*t->str);
		
		if (*t->str == '#')
			t->prefixe = 1;
		else if (*t->str == '0' && t->aligne_g == 0 && t->precision < 0)
			t->zeros = 1;
		else if (*t->str != '0' && ft_isdigit(*t->str))
		{
			t->sizemin = ft_atoi(t->str);
			while (ft_isdigit(*(t->str + 1)))
			t->str++;
		}
		else if (ft_strchr("-+ .", *t->str))
			ft_flags_ponct(t);
		else if (ft_strchr("hljz", *t->str))
			ft_flags_conversion(t);
//		ft_putendl("fini while");
//		ft_putchar(*t->str);
//		ft_putendl(" is char");
//		ft_putnbr(t->zeros);
//		ft_putnbr(t->aligne_g);
//		ft_putendl(" is zero");
//		ft_putnbr(t->precision);
//		ft_putendl(" is precision");
//		ft_putnbr(t->sizemin);
//		ft_putendl(" is sizemin\n");
		t->str++;
	}
//	ft_putstr("lalalala\n");
//	ft_putstr(t->str);
//	ft_putchar('[');
//	ft_putchar(*t->str);
//	ft_putstr("]\n");
	if (*t->str != '\0')
		ft_parse_specifier(t);
//	ft_putstr(t->str);
//	else
//	{
//		ft_putendl("on sort");
//		exit(0);
//	}
}
