
#include "ft_printf.h"

int ft_float_len(float f, int precision, int *lp_ent, int *lp_dec)
{
	*lp_ent = ft_size((int)f);
	while(10 * f != 10 * (int)f)
	{
		f *= 10;
		*lp_dec += 1;
	}
	if (precision > 0)
		return(*lp_ent + precision + 1);
	else if (precision < 0)
		return (*lp_ent + 6 + 1);
	else
		return (*lp_ent);
}

int ft_float2int(double f, long long int *a, long long int *b, int precision)
{
//	ft_putendl("float2int");
	int	p_ent = 0; 
	int	prec = 1;
	int	ret = 1;
	double p_dec = 0;

	prec = ft_power(10, precision);
	p_ent = (int)f;
//	ft_putnbr(p_ent);
//	ft_putendl("float2int");
	p_dec = f - p_ent;
	*a = p_ent;
	*b = (int)(p_dec * prec);
//	ft_putnbr((int)(f * prec));
//	ft_putendl("float2int");
//	ft_putnbr(prec);
//	ft_putendl("float2int");
	if(*b != p_dec * prec)
	{
//		ft_putendl("ici");
		if((int)(p_dec * prec * 10) % 10 >= 5)
			*b += 1;
//		ft_putchar(*b);
	}
	while (p_dec && (int)(p_dec * 10) == 0 && ret < precision)
	{
		ret++;
		p_dec = p_dec * 10;
	}
	return (ret - 1);
}

void ft_putfloat2(double f, int precision)
{
	int reste = 0;
	int zero = 0;
	int b, a;
	ft_putnbr((long long)f);
	if (precision)
		ft_putchar('.');
	if (precision == -1)
		precision = 6;
//	ft_putnbr(precision);
//	ft_putendl(" is precision");
	if (precision >= 6)
	{
		reste = precision - 6;
		precision = 6;
	}
	zero = ft_float2int(f, &a, &b, precision);
//	ft_putnbr(zero);
//	ft_putendl("is zeros");
//	ft_putendl("is the 0s");
	if (b)
	{
		ft_putc_times('0', zero);
		ft_putnbr(b);
	}
	if (!b && precision)
		ft_putc_times('0', precision);
//	ft_putendl("is dec");
//	while(precision > 0)
//	{
			//printf("\nI%fI\n", f);
//		f = 10 * (f - (int)f);

		//printf("\nI%lfI\n", f);
		//printf("\nI%dI\n", (int)f);
//		ft_putnbr((long long)f);
		//ft_putnbr((int)f);
//		precision--;
//	}
	//printf("%lf",rest);
	ft_putc_times('0', reste);
//	ft_putnbr(reste);
//	ft_putendl("is rest");
}

void ft_putfloat(t_stringinfo *t)
{
	int len = 0;
	int lp_ent = 0;
	int lp_dec = 0;
	t->f = va_arg(t->ap, double);
//	ft_putnbr(t->sign);
//	ft_putstr("passe par print \n");
	len = ft_float_len(t->f, t->precision, &lp_ent, &lp_dec);
//	ft_putstr("toto ");
//	ft_putnbr(len);
//	ft_putendl(" toto");

	t->precision = (t->precision < 0) ? 6 : t->precision;
	t->sizemin = (t->sizemin > len) ? t->sizemin - len : 0;
	t->len += t->sizemin + len;
//	ft_putnbr(t->sizemin);
	if (t->f < 0 || t->sign || (t->space && t->f >= 0))
	{
		if(t->sizemin <= 0)
			t->len++;
		t->sizemin--;
//		ft_putnbr(t->len);
	}
	if (t->space && t->f >= 0)
		ft_putchar(' ');
	if (t->zeros > 0)
	{
		if (t->f < 0)
			ft_putchar('-');
		if (t->f >= 0 && t->sign == 1)
			ft_putchar('+');
	}
	if (!t->aligne_g)
	{
		if (t->zeros)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
//		while (t->sizemin-- > 0)
//		{
//			if(t->zeros)
//				ft_putchar('0');
//			else
//				ft_putchar(' ');
//		}
	}
	if(!t->zeros)
	{
		if (t->f < 0)
			ft_putchar('-');
		if (t->f >= 0 && t->sign == 1)
			ft_putchar('+');
	}
	ft_putfloat2(t->f, t->precision);
	if (t->aligne_g)
	{
		ft_putc_times(' ', t->sizemin);
//		while (t->sizemin-- > 0)
//			ft_putchar(' ');
	}
	t->ret += t->len;
//	ft_putendl("lololol");
}
