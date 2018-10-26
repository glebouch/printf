/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:35:35 by glebouch          #+#    #+#             */
/*   Updated: 2017/12/20 14:39:58 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int a = 10;
//	char *str = "toto d";
	ft_printf("\"\t%0#24O\n", 1567567);
	a = printf("\"\t%0#24lo\n", 1567567L);
	printf("a = %d\n", a);
	ft_printf("a = %d\n", a);
	printf("a = \"%24.10d\"\n", -42);
	ft_printf("a = \"%24.10d\"\n", -42);
	printf("%+d\n", -34);
	ft_printf("%+d\n", -34);
	printf("%+d et %#o\n", -34, 89);
	ft_printf("%+d et %#o\n", -34, 89);
	printf("%-+itoto\n", -25);
	ft_printf("%-+itoto\n", -25);
	printf("%itoto\n", -36);
	ft_printf("%itoto\n", -36);
	printf("%d\n", 36);
	ft_printf("%d\n", 36);
	printf("%12toto\n", 356489);
	printf("%12ttoto\n", 356489);
	ft_printf("%12toto\n", 356489);

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