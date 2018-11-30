/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:55:44 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 19:20:07 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ft_signed2(t_stringinfo *t)
{
	int len;
	int precision_init_zero = 0;
//	ft_putstr("passe par print\n");
	len = ft_size_base((size_t)ft_imaxabs((intmax_t)t->nbr), 10);
//	if (t->space && t->nbr >= 0 && !t->signe)
//		t->len = 1;
	if(t->precision == 0 && t->nbr == 0)
//		precision_init_zero = 1;
		len = 0;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
//	ft_putnbr(t->len);
	if (t->nbr < 0 || t->sign || (t->space && t->nbr >= 0))
	{
		if(t->sizemin <= 0)
			t->len++;
		t->sizemin--;
//		ft_putnbr(t->len);
	}
	if (t->space && t->nbr >= 0)
		ft_putchar(' ');
	if (t->zeros > 0)
	{
		if (t->nbr < 0)
			ft_putchar('-');
		if (t->nbr >= 0 && t->sign == 1 && (*t->str == 'd' || *t->str == 'D'))
			ft_putchar('+');
	}
	if (!t->aligne_g)
	{
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	if(t->zeros <= 0)
	{
		if (t->nbr < 0)
			ft_putchar('-');
		if (t->nbr >= 0 && t->sign == 1 && ft_strchr("Ddi", *t->str))
			ft_putchar('+');
	}
//	while (t->precision-- > 0)
//		ft_putchar('0');
	ft_putc_times('0', t->precision);
	if (len)
		ft_putnbr_base(ft_imaxabs((intmax_t)t->nbr), 10, 0, 0);
	if (t->aligne_g)
	{
		ft_putc_times(' ', t->sizemin);
//		while (t->sizemin-- > 0)
//			ft_putchar(' ');
	}
	t->ret += t->len;
}


void	ft_signed(t_stringinfo *t)
{
//	ft_putendl("dans signed");
//	ft_putnbr(t->conversion);
	if (*t->str == 'D' || t->conversion == 3)
		t->nbr = va_arg(t->ap, long int);
	else if (t->conversion == 1)
		t->nbr = (char)va_arg(t->ap, int);
	else if (t->conversion == 2)
		t->nbr = (short)va_arg(t->ap, int);
	else if (t->conversion == 4)
		t->nbr = va_arg(t->ap, long long);
	else if (t->conversion == 5)
		t->nbr = va_arg(t->ap, intmax_t);
	else if (t->conversion == 6)
		t->nbr = va_arg(t->ap, size_t);
	else if (t->conversion == 0)
		t->nbr = va_arg(t->ap, int);
//	ft_putnbr(t->nbr);
	ft_signed2(t);
}
