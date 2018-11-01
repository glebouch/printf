
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
	return (0);
}

void	ft_line_unsigned(t_stringinfo *t, int base, int maj)
{
	int len;
//	ft_putstr("passe par print\n");

	len = ft_size_base((size_t)t->unbr, base);
	if (t->space && t->precision > t->sizemin)
		t->len = 1;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
	if (!t->aligne_g)
	{
		if(t->prefixe)
			t->sizemin--;
		if(t->prefixe && base == 16)
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
	t->ret += t->len;
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
	{
		t->prefixe = 1;
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
