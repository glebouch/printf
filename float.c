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

int		ft_float_len(float f, int precision, int *lp_ent, int *lp_dec)
{
	*lp_ent = ft_size((int)f);
	while (10 * f != 10 * (int)f)
	{
		f *= 10;
		*lp_dec += 1;
	}
	if (precision > 0)
		return (*lp_ent + precision + 1);
	else if (precision < 0)
		return (*lp_ent + 6 + 1);
	else
		return (*lp_ent);
}

int		ft_float2ll(long double f, long long *a, long long *b, int precis)
{
//	ft_putstr(" passe par float2ll ");
	long long int	p_ent;
	long long int	prec;
	int				ret = 1;
	long double		p_dec;

	prec = ft_power(10, precis);
	p_ent = (int)f;
	p_dec = f - p_ent;
	*a = p_ent;
	*b = (long long int)(p_dec * prec);
	if (*b != p_dec * prec)
	{
		if ((long long int)(p_dec * prec * 10) % 10 >= 5)
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
	int		p_ent = 0;
	int		prec = 1;
	int		ret = 1;
	double	p_dec = 0;

	prec = (int)ft_power(10, precis);
	p_ent = (int)f;
	p_dec = f - p_ent;
	*a = p_ent;
	*b = (int)(p_dec * prec);
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
	int reste = 0;
	int zero = 0;
	long long b;
	long long a;

	ft_putnbr((long long)f);
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
	int len = 0;
	int lp_ent = 0;
	int lp_dec = 0;

//	ft_putnbr(t->long_double);
	t->f = (t->long_double) ? va_arg(t->ap, long double) : va_arg(t->ap, double);
	len = ft_float_len(t->f, t->precision, &lp_ent, &lp_dec);
//	ft_putnbr(len);
	t->long_double = (t->precision > 6) ? 1 : 0;
	t->precision = (t->precision < 0) ? 6 : t->precision;
//	ft_putnbr(t->precision);
	t->sizemin = (t->sizemin > len) ? t->sizemin - len : 0;
	t->ret += t->sizemin + len;
	if (t->f < 0 || t->sign || (t->space && t->f >= 0))
	{
		if (t->sizemin <= 0)
			t->len++;
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
		if (t ->zeros)
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
