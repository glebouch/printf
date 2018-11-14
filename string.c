/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:18:51 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_nb_l_print(t_stringinfo *t, char *str)
{
	int i = 0;
	int oct = 0;

	if (t->precision == 0)
		return(-1);
	if (t->precision > 0)
	{
		while (oct <= t->precision && str[i])
		{
			oct += ft_octet(str[i]);
			if(oct <= t->precision)
				i++;
		}
	}
	else
	{
		ft_putendl(str);
		while (str[i])
		{
			ft_putendl(str);
			i++;
		}
	}
	return(i);
}

int 	ft_oct_print(t_stringinfo *t, int nb_l_print)
{
	int i = 0;
	int oct = 0;

	while (i < nb_l_print && t->string[i])
	{
		oct += ft_octet(t->string[i]);
		i++;
	}
	return (oct);
}
*/
int		ft_str(t_stringinfo *t)
{
	int len = 0;
//	ft_putendl("ta mere");

	t->string = (char *)va_arg(t->ap, char *);
	if (t->string == NULL)
	{
		ft_putstr("(null)");
		t->ret += 6;
		return(0);
	}
	len = ft_strlen(t->string);
	if (t->precision > len || t->precision <= 0)
		t->precision = len;
	t->sizemin = (t->precision < t->sizemin) ? t->sizemin - t->precision : 0;
	t->ret += t->sizemin + t->precision;
	if (!t->aligne_g)
	{
		while (t->sizemin-- > 0)
		{
//			if(t->zeros)
//				ft_putchar('0');
//			else
				ft_putchar(' ');
		}
	}
	if (!t->string)
		ft_putstr("(null)");
	if (t->string[0])
		ft_putnstr(t->string, t->precision);
	if (t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
	return(0);
}
/*void	ft_str(t_stringinfo *t)
{
	t->string = (char *)va_arg(t->ap, char *);
//	ft_putstr(t->string);
	int nb_l_print;
	int oct;
	int i = 0;

	nb_l_print = ft_nb_l_print(t, t->string);
	ft_putnbr(nb_l_print);
	ft_putchar('\n');
	oct = ft_oct_print(t, nb_l_print);
	ft_putnbr(oct);
	ft_putchar('\n');
	t->sizemin = (t->sizemin > oct) ? t->sizemin - oct : 0;
	t->ret += t->sizemin + oct;
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
	while(i < nb_l_print)
	{
		if (t->string[i] < 127)
			ft_putchar(t->string[i]);
		else
			ft_putchar_unicode(t->string[i], ft_octet(t->string[i]));
		i++;
	}
	if (t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
}*/