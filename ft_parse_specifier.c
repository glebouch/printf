/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:18:51 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
** %[specifier] == d, i, o, u, x, X, c, s, C, S, p, D, O, U;
**
*/


void	ft_putchar_unicode(wchar_t caract, int oct)
{
//	ft_putendl("passe par ici");
	unsigned char tab[5] = {192, 128, 0, 0, 0};
	int i = 1;

	if (oct == 3)
	{
		tab[0] = 224;
		tab[2] = 128;
	}
	else if (oct == 4)
	{	
		tab[0] = 240;
		tab[2] = tab[3] = 128;
	}
	while (i <= oct)
	{
		tab[oct - i] += caract & 63;
		caract = caract >> 6;
		i++;
	}
	i = 0;
	while(tab[i])
		ft_putchar(tab[i++]);
}
/*

110 1110 11110 1000 0000
i = 0
boucle ()
	tab[nb_char - i] += current_value & 63
	current_value = current_value >> 6;
	i++  

*/
int ft_octet(wchar_t caract)
{
	int len;

	len = ft_size_base(caract, 2);
	if (len <= 7)		
		return (1);
	if (len <= 11)
		return (2);
	if (len <= 16)
		return (3);
	if (len <= 21)
		return (4);
	return (0);
}

void	ft_char2(t_stringinfo *t)
{
	int oct;

	oct = ft_octet(t->ch);
	t->sizemin = (t->sizemin > oct) ? t->sizemin - oct : 0;
	t->len += t->sizemin + oct;
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

int		ft_nb_l_print(t_stringinfo *t)
{
	int i = 0;
	int oct = 0;
	if (t->precision <= 0)
		return(-1);
	while (oct <= t->precision && t->string[i])
	{
		oct += ft_octet(t->string[i]);
		if(oct <= t->precision)
			i++;
	}
	return(i);
}

int 		ft_oct_print(t_stringinfo *t, int nb_l_print)
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


void	ft_str(t_stringinfo *t)
{
	t->string = (wchar_t *)va_arg(t->ap, wchar_t *);
	
	int nb_l_print;
	int oct;
	int i = 0;

	nb_l_print = ft_nb_l_print(t);
	oct = ft_oct_print(t, nb_l_print);
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
}

void	ft_char(t_stringinfo *t)
{
	if (*t->str != 'c' && *t->str != 'C')
		t->ch = *t->str;
	else if (t->conversion == 3 || *t->str == 'C')
		t->ch = (wchar_t)va_arg(t->ap, unsigned int);
	else if (*t->str == 'c')
		t->ch = (wchar_t)va_arg(t->ap, unsigned int);
	ft_char2(t);
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
/*
00000000000000011101011010  48454
00000000000000000110110110
00000000000000101101110111
110xxxxx 10xxxxxx

00000000 00000000
10000000
11000000
11000000 10000000


char tab[2];

tab[0] = 0;
tab[1] = 0;
tab[0] = 192;
tab[1] = 128;


i = 0
boucle ()
	tab[nb_char - i] += current_value & 63
	current_value = current_value >> 6;
	i++  


11000000 10000000


00000000000000000000111111
00000000000000011101011010
__________________________
00000000000000000000011010
				  10000000
				  ________
				  10011010

00000000000000000000111111
      00000000000000011101//011010
__________________________
				  00011101
				  11000000
				  ________

				  110111
00000111   111111   111111   111111
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx









11010000


00000001
00000010
00000100
00001000
00010000
00100000
01000000
01111111
10000000
11000000


11011101 10011010
11000110 10110110
11100000 10011101 10110111*/
//OUp -> ne peut pas etre converti


//ouxX -> peut etre converti
