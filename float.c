/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:55:44 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 19:20:07 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_float_len(t_stringinfo *t)
{
	int l_p_ent;

	l_p_ent = ft_size((uintmax_t)t->f);
	if (t->precision > 0)
		return (l_p_ent + t->precision + 1);
	else if (t->precision < 0)
		return (l_p_ent + 6 + 1);
	else
		return (l_p_ent);
}

int		ft_float2ll(long double f, long long *a, long long *b, int precis)
{
	long long	p_ent;
	long long	prec;
	int			ret;
	long double	p_dec;

	ret = 1;
	prec = ft_power(10, precis);
	p_ent = (long long)f;
	p_dec = f - p_ent;
	*a = p_ent;
	*b = (long long)(p_dec * prec);
	if (*b != p_dec * prec)
	{
		if ((long long)(p_dec * prec * 10) % 10 >= 5)
			*b += 1;
	}
	while (p_dec && (int)(p_dec * 10) == 0 && ret < precis)
	{
		ret++;
		p_dec = p_dec * 10;
	}
	return (ret - 1);
}

int		ft_float2int(double f, int *a, int *b, int precis)
{
//	ft_putendl("passe float2int");
	int		p_ent;
	int		prec;
	int		ret;
	float	p_dec;

	ret = 1;
//	ft_putendl("passe float2int2");
	prec = (int)ft_power(10, precis);
//	ft_putendl("passe float2int3");
	p_ent = (int)f;

//	ft_putendl("passe float2int4");
	p_dec = f - p_ent;

//	ft_putendl("passe float2int5");
	*a = p_ent;

//	ft_putendl("passe float2int6");
	*b = (int)(p_dec * prec);

//	printf("b{%f}", *b);
	ft_putnbr(*b);
//	ft_putendl("passe float2int7");

//	printf("p{%d}", prec);
//	printf("bn{%d}", (int)(p_dec * prec));
//	printf("pd{%f}", p_dec);
	printf("pd*p{%f}\n", p_dec * prec);
//	ft_putendl("passe float2int8");
	if (*b != p_dec * prec)
	{
		if ((int)(p_dec * prec * 10) % 10 >= 5)
			*b += 1;
	}
	while (p_dec && (int)(p_dec * 10) == 0 && ret < precis)
	{
		ret++;
		p_dec = p_dec * 10;
	}
	return (ret - 1);
}

void	ft_putfloat2(t_stringinfo *t, long double f, int precision)
{
	int			reste = 0;
	int			zero = 0;
	long long	b;
	long long	a;

	ft_putll((long long)f);
	if (precision)
		ft_putchar('.');
	if (precision >= 6 && !t->long_double)
	{
		reste = precision - 6;
		precision = 6;
	}
	if (!t->long_double)
		zero = ft_float2int((double)f, (int *)&a, (int *)&b, precision);
	else
		zero = ft_float2ll(f, &a, &b, precision);
	if (b)
	{
		ft_putc_times('0', zero);
		ft_putll(b);
	}
	if (!b && precision)
		ft_putc_times('0', precision);
	ft_putc_times('0', reste);
}

void	ft_putfloat(t_stringinfo *t)
{
	int len;

	t->f = (t->long_double) ? va_arg(t->ap, long double) : va_arg(t->ap, double);
	len = ft_float_len(t);
	t->long_double = (t->precision > 6) ? 1 : t->long_double;
	t->precision = (t->precision < 0) ? 6 : t->precision;
	t->sizemin = (t->sizemin > len) ? t->sizemin - len : 0;
	t->ret += t->sizemin + len;
//	ft_putstr("\niii");
//	ft_putnbr(t->long_double);
//	ft_putnbr(len);
//	ft_putnbr(t->aligne_g);
//	ft_putnbr(t->precision);
//	ft_putendl("iii");

	if (t->f < 0 || t->sign || (t->space && t->f >= 0))
	{
		if (t->sizemin <= 0)
			t->ret++;
		t->sizemin--;
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
	}
	if (t->zeros <= 0)
	{
		if (t->f < 0)
			ft_putchar('-');
		if (t->f >= 0 && t->sign == 1)
			ft_putchar('+');
	}
	ft_putfloat2(t, t->f, t->precision);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
}
