/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:35:35 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:23:52 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

void	ft_putc_times(char c, int i)
{
	char *str;
	str = ft_strnew(i + 1);	

	if (i > 0)
	{
		str[i] = '\0';
		i--;
		while (i >= 0)
		{
			str[i] = c;
//			ft_putnbr(i);
			i--;
		}
		ft_putstr(str);
	}
	free(str);
}

int	ft_percent(t_stringinfo *t)
{
	t->str++;
	ft_init(t);
	if (*t->str && ft_strchr("123456789-+0 #.sSpdDioOuUfxXcChljz", *t->str))
	{
//		ft_putstr("tamere\n");
		ft_parse_flags(t);
	}
	else if (*t->str)
	{
//		ft_putendl("totoici");
		ft_putchar(*t->str);
		t->ret++;
	}
	return (0);
}

int		ft_start(t_stringinfo *t)
{
	while (*t->str != '\0')
	{
//		if (*t->str == '\%')
//			ft_putchar('%');
		if (*t->str == '%')
			ft_percent(t);
		else if (*t->str != '%')
		{
			ft_putchar(*t->str);
			t->ret++;
		}
		if(*t->str)
			t->str++;
	}
	return (0);
}

int ft_printf(char *str, ...)
{
	t_stringinfo t;
	int ret = 0;

	ft_bzero((void *)&t, sizeof(t));
	t.str = str;
	va_start(t.ap, str);
	ft_start(&t);
	va_end(t.ap);
	return(t.ret);
}



/*
d i
o u x X

hh h l ll j z


c
s
C
S
p


%

D O U*/
