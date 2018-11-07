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

const char	*ft_ctoa(char c, int i)
{
	char *str;
	str = ft_strnew(i);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = c;
		i--;
	}
	return (str);
}

void	ft_percent(t_stringinfo *t)
{
	t->str++;
	ft_init(t);
	if (ft_strchr("123456789-+0 #.sSpdDioOuUxXcChljz", *t->str))
	{
//		ft_putstr("tamere\n");
		ft_parse_flags(t);
	}
	else
		ft_putchar(*t->str);
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
		t->str++;
	}

	return (0);
}

int ft_printf(char *str, ...)
{
	t_stringinfo t;
	int ret;

	ft_bzero((void *)&t, sizeof(t));
	t.str = str;
	va_start(t.ap, str);
	ft_start(&t);
	va_end(t.ap);
	return(t.ret);
}

int main (void)
{
	int a;
//	char *str = "toto d";
//	ft_printf("\"\t%0#24O\n", 1567567);
//	a = printf("\"\t%0#24lo\n", 1567567L);
//	printf("a = %d\n", a);
//	ft_printf("a = %d\n", a);
//	printf("a = \"%24.10d\"\n", -42);
//	ft_printf("a = \"%24.10d\"\n", -42);
//	printf("%+d\n", -34);
//	ft_printf("%+d\n", -34);
//	printf("%+d et %#o\n", -34, 89);
//	ft_printf("%+d et %#o\n", -34, 89);
//	printf("%-+itoto\n", -25);
//	ft_printf("%-+itoto\n", -25);
//	printf("%itoto\n", -36);
//	ft_printf("%itoto\n", -36);
//	printf("%d\n", 36);
//	ft_printf("%d\n", 36);
/*	a = printf("%12d\n", 356489);
	ft_putnbr(a);
	a = ft_printf("%12d\n", 356489);
	ft_putnbr(a);
	a = printf("%12k\n", -356489);
	ft_putnbr(a);
	a = ft_printf("%12k\n", -356489);
	ft_putnbr(a);

	a = printf("\ntoto[%-4 d]\n", 123456);
	ft_putnbr(a);
	a = printf("\ntoto[%-12.14 d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%-12.14d]\n", -15);
	ft_putnbr(a);
	a = printf("\ntoto[%-12.14d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%+12.14 d]\n", -15);
	ft_putnbr(a);
	a = printf("\ntoto[%12 d]\n", -15);
	ft_putnbr(a);
	a = printf("\ntoto[%012 d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[% #.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%012d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%- d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[% d]\n", 15);

	ft_putnbr(a);
	a = ft_printf("\ntoto[%-4 d]\n", 123456);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%-12.14 d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%-12.14d]\n", -15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%-12.14d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%+12.14 d]\n", -15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%12 d]\n", -15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%012 d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%012d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%- d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[% d]\n", 15);
*/
	setlocale(LC_ALL, "");
	a = printf("\ntoto[%.0d]\n", 1298);
	ft_putnbr(a);

	a = ft_printf("\ntoto[%.0d]\n", 1298);
		ft_putnbr(a);

/*  a = printf("[%12o]\n", 356489);
	ft_putnbr(a);
	a = printf("[%12lo]\n", 356489);
	ft_putnbr(a);
	a = printf("[%12x]\n", 356489);
	ft_putnbr(a);
	a = printf("[%12X]\n", 356489);
	ft_putnbr(a);
	a = printf("\n[%-4 x]\n", 123456);
	ft_putnbr(a);
//	a = printf("\n[%-12.14 X]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%-12.14X]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%-12.14x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%+12.14 x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%12 x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%012 x]\n", 15);
	ft_putnbr(a);
//	a = printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%012x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%- x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% x]\n", 15);
	ft_putnbr(a);

	a = ft_printf("[%12o]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("[%12O]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("[%12x]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("[%12X]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("\n[%-4 x]\n", 123456);
	ft_putnbr(a);
	a = ft_printf("\n[%-12.14 X]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%-12.14X]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%-12.14x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%+12.14 x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%12 x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%012 x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%012x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%- x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% x]\n", 15);


	printf("\n\n\n\n");
	a = printf("\n[%#.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% .8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%#.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% .8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
*/
//	printf("%s\n", "356489");
//	ft_printf("%s\n", "356489");
//	ft_printf("%O\n", 1567567);
//	ft_printf("%u\n", 1567567);
//	ft_printf("%U\n", 1567567);
//	ft_printf("%x\n", 1567567);
//	ft_printf("%X\n", 1567567);
//	ft_printf("%p\n", &a);
//	printf("%%%% toto");
	return (0);
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
