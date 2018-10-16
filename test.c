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
	if (ft_strchr("123456789-+0 #.sSpdDioOuUxXcChljz", *t->str))
		ft_parse_flags(t);
	else
		t->line = ft_strjoin(t->line, ft_ctoa(*t->str, 1));
}

int		ft_start(t_stringinfo *t)
{
	char	current;

	while ((current = *t->str) != '\0')
	{
		if (current != '%')
		{
			t->line = ft_strjoin(t->line, ft_ctoa(current, 1));
//			ft_putendl(t->line);
		}
		else
			ft_percent(t);
		t->str++;
//		ft_putendl(str);
	}

	return (0);
}

int ft_printf(char *str, ...)
{
	t_stringinfo t;
	int ret;

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
//	char *str = "toto d";
	ft_printf("%toto\n");
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