/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:55:58 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:27:36 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_prefix(t_stringinfo *t, int base, int maj)
{
	if (!t->prefixe)
		return(0);
	if (base == 8)
		ft_putchar('0');
	else if (base == 16 && maj)
		ft_putstr("0X");
	else if (base == 16)
		ft_putstr("0x");
//	if (t->precision <= 0 && t->sizemin <= 0)
//		t->len += (base == 16) ? 2 : 1;
	return (0);
}

void	ft_line_unsigned(t_stringinfo *t, int base, int maj)
{
	int len;
	int precision_init_zero = 0;
//	printf("ou [%jx]\n", t->unbr);
//	ft_putstr("passe par print\n");

	len = ft_size_base((size_t)t->unbr, base) + t->prefixe;
//	if (t->space && t->precision > t->sizemin)
//		t->len = 1;
	if(t->precision == 0 && t->unbr == 0 && base != 8)
		len = 0;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
	if (!t->aligne_g)
	{
		if(t->prefixe && t->zeros && t->unbr)
		{
			ft_prefix(t, base, maj);
			t->prefixe = 0;
		}
		while (t->sizemin-- > 0)
		{
			if(t->zeros)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
//	ft_putendl("check");
//	ft_putnbr(t->unbr);
	if(t->unbr != 0)
		ft_prefix(t, base, maj);
	while (t->precision-- > 0)
		ft_putchar('0');
//	if (!len)
//		t->ret--;
	if (len)
		ft_putnbr_base(t->unbr, base, maj, 0);
	if (t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
	t->ret += t->len;
}
void	ft_unsigned2(t_stringinfo *t)
{
	if (!t->unbr)
		t->prefixe = 0;
	if (*t->str == 'o')
		ft_line_unsigned(t, 8, 0);
	if (*t->str == 'O')
		ft_line_unsigned(t, 8, 1);
	if (*t->str == 'u' || *t->str == 'U')
		ft_line_unsigned(t, 10, 0);
	if (*t->str == 'x')
		ft_line_unsigned(t, 16, 0);
	if (*t->str == 'X')
		ft_line_unsigned(t, 16, 1);
	if (*t->str == 'p')
	{
		t->prefixe = (t->unbr) ? 2 : 0;
		ft_line_unsigned(t, 16, 0);
	}
}

void	ft_unsigned(t_stringinfo *t)
{
//	uintmax_t unbr;
	if (t->conversion == 3 || *t->str == 'O' || *t->str == 'U' || *t->str == 'p')
		t->unbr = va_arg(t->ap, unsigned long int);
	else if (t->conversion == 1)
		t->unbr = (unsigned char)va_arg(t->ap, unsigned int);
	else if (t->conversion == 2)
		t->unbr = (unsigned short)va_arg(t->ap, unsigned int);
	else if (t->conversion == 4)
		t->unbr = va_arg(t->ap, unsigned long long);
	else if (t->conversion == 5)
		t->unbr = va_arg(t->ap, uintmax_t);
	else if (t->conversion == 6)
		t->unbr = va_arg(t->ap, size_t);
	else if (t->conversion == 0)
		t->unbr = va_arg(t->ap, int);
	ft_unsigned2(t);
}
