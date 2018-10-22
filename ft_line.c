/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/05/18 15:37:41 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(uintmax_t n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

void	ft_putnbr_base(uintmax_t n, int base, int maj, int neg)
{
	char *tab;

	if (neg)
		write(1, "-", 1);
	if (maj)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if ((n / base) != 0)
		ft_putnbr_base(n / base, base, maj, 0);
	ft_putchar(tab[n % base]);
}

void ft_prefix(t_stringinfo *t, int base, int maj)
{
	if (base == 8)
		ft_putchar('0');
	else if (base == 16 && maj)
		ft_putstr("0X");
	else if (base == 16)
		ft_putstr("0x");
}

void	ft_line_unsigned(t_stringinfo *t, int base, int maj)
{
	int len;
	ft_putstr("passe par print\n");

	len = ft_size((size_t)t->unbr);
	if (t->space && t->precision > t->sizemin)
		t->len = 1;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
	if (!t->aligne_g)
	{
		if(t->prefixe)
			t->sizemin--;
		while (t->sizemin-- > 0)
		{
			if(t->zeros)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	ft_prefix(t, base, maj);
	while (t->precision-- > 0)
		ft_putchar('0');
	ft_putnbr_base(t->unbr, base, maj, 0);
	if (t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
}

void	ft_unsigned2(t_stringinfo *t)
{
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
		ft_line_unsigned(t, 16, 0);

}