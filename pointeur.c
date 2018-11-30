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

int	ft_octal_no_prefixe(t_stringinfo *t, int base)
{
	int len;
	int print_nullunbr = 1;

//	ft_putendl("prefixe = 0");
	len = ft_size_base((size_t)t->unbr, base);
//	ft_putnbr(len);
	if(!t->precision && !t->unbr)
	{
		print_nullunbr = 0;
		len = 0;
	}
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
//	ft_putnbr(t->len);
	if (!t->aligne_g)
	{
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	ft_putc_times('0', t->precision);
	if(print_nullunbr)
		ft_putnbr_base(t->unbr, base, 0, 0);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
	t->ret += t->len;
}

int	ft_octal_prefixe(t_stringinfo *t, int base)
{
	int len;

	len = ft_size_base((size_t)t->unbr, base);
	if(!t->unbr)
		len = 0;
//	ft_putnbr(len);
	t->precision = (t->precision > len) ? t->precision - len : 0;
	if(t->precision == 0)
		t->precision = 1;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
//	ft_putnbr(t->len);
	if (!t->aligne_g)
	{
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	ft_putc_times('0', t->precision);
	if (t->unbr)
		ft_putnbr_base(t->unbr, base, 0, 0);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
	t->ret += t->len;
}


void	ft_pointeur(t_stringinfo *t, int base, int maj)
{
	int len;
	int print_nbr = 1;

	len = ft_size_base((size_t)t->unbr, base);
	if (!t->unbr && t->zeros)
		t->aligne_g = 0;
	if(t->precision == 0 && !t->unbr)
	{
		len = 0;
		print_nbr = 0;
	}
//	ft_putnbr(t->precision);
//	ft_putnbr(len);
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len + t->prefixe) ? t->sizemin - (t->precision + len + t->prefixe) : 0;
	t->len += t->sizemin + t->precision + len + t->prefixe;
//	ft_putnbr(t->len);
	if (!t->aligne_g)
	{
		if(t->zeros > 0)
		{
			ft_prefix(t, base, maj);
			t->prefixe = 0;
//			ft_putendl("toto");
		}
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
//	ft_putendl("check");
//	ft_putnbr(t->unbr);
	if(t->prefixe == 2)
		ft_prefix(t, base, maj);
	ft_putc_times('0', t->precision);
//	while (t->precision-- > 0)
//		ft_putchar('0');
//	if (!len)
//		t->ret--;
	if (print_nbr)
		ft_putnbr_base(t->unbr, base, maj, 0);
	if (t->aligne_g)
	{
		ft_putc_times(' ', t->sizemin);
//		while (t->sizemin-- > 0)
//			ft_putchar(' ');
	}
	t->ret += t->len;
//	if (t->prefixe == 2)
//		t->ret += 2;
}