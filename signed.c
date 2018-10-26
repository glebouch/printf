


#include "ft_printf.h"

void ft_signed2(t_stringinfo *t)
{
	int len;
//	ft_putstr("passe par print\n");

	len = ft_size((size_t)imaxabs((intmax_t)t->nbr));
	if (t->space && t->precision > t->sizemin)
		t->len = 1;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
	if (t->nbr < 0 || t->sign)
		t->sizemin--;
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
	if (t->nbr < 0)
		ft_putchar('-');
	if (t->nbr >= 0 && t->sign == 1 && *t->str == 'd')
		ft_putchar('+');
	while (t->precision-- > 0)
		ft_putchar('0');
	ft_putnbr_base(imaxabs((intmax_t)t->nbr), 10, 0, 0);
	if (t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
}


void	ft_signed(t_stringinfo *t)
{
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
	ft_signed2(t);
}