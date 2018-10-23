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
/*void ft_backslash(t_stringinfo *t)
{
	t->str++;
	if (*t->str == '\\' || *t->str == '\"' || *t->str == '\'' || *t->str == '')

	if (*t->str == 't' || *t->str == 'n' || *t->str == 'r' || *t->str == '0')
}*/

void	ft_percent(t_stringinfo *t)
{
	t->str++;
	if (ft_strchr("123456789-+0 #.sSpdDioOuUxXcChljz", *t->str))
		ft_parse_flags(t);
	else
		ft_putchar(*t->str);
}

int		ft_start(t_stringinfo *t)
{
	while (*t->str != '\0')
	{
		if (*t->str == '\%')
			ft_putchar('%');
		else if (*t->str == '%')
			ft_percent(t);
		else if (*t->str != '%')
		{
			ft_putchar(*t->str);
//			t->line = ft_strjoin(t->line, ft_ctoa(current, 1));
//			ft_putendl(t->line);
		}
		
		t->str++;
//		ft_putendl(str);

	}

	return (0);
}

int ft_printf(char *str, ...)
{
	t_stringinfo t;
	int ret;

	ft_bzero((void *)&t, sizeof(t));
	t.str = str;
	t.line = ft_strnew(0);
	va_start(t.ap, str);
	ret = ft_start(&t);
	va_end(t.ap);
	ft_putstr(t.line);
	return(ret);
}

int main (void)
{
	int a = 10;
//	char *str = "toto d";
	ft_printf("\"\t%0#24O\n", 1567567);
	a = printf("\t%0#24lo\n", 1567567);
	printf("a = %d\n", a);
	printf("\ntoto\n");
	ft_printf("\ntoto\n");
	printf("\ttoto\n");
	ft_printf("\ttoto\n");
	printf("\rtoto\n");
	ft_printf("\rtoto\n");
	printf("\\\n");
	ft_printf("\\\n");
	printf("\"\'\%\n");
	ft_printf("\"\'\%\n");
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