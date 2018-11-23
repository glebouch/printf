#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <locale.h>
#include <limits.h>
#include <math.h>

/*

static int	ft_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char		*ft_ftoa(float f)
{
	int		size;
	char	*s;
	int i = 0;

	size = ft_size((int)f) + 7;
	if (f == 0)
		return (ft_strdup("0.000000"));
	if (f < 0)
		size++;
	if (!(s = (char *)malloc(size + 1)))
		return (NULL);
	if (f < 0)
	{
		s[0] = '-';
		f = -f;
	}
	s[size] = '\0';
	while (f !=  (long)f)
	{
		f *= 10;
		i++;
	}
	while (f != 0)
	{
		if(i)
		s[size - 1] = n % 10 + 48;
		n = n / 10;
		--size;
	}
	return (s);
}
123.123

1231.23
12312.3
123123.0

*/
void	ft_putc_times(char c, int i)
{
	char *str;
	str = ft_strnew(i);	

	if (i > 0)
	{
		str[i] = '\0';
		i--;
		while (i >= 0)
		{
			str[i] = c;
//			ft_putnbr(i);
			i--;
		}
		ft_putstr(str);
	}
	free(str);
}

int	ft_size(uintmax_t n)
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

int ft_float_len(double f)
{
	int i;
	int j = 0;

	i = ft_size((int)f);
	while(10 * f != 10 * (int)f)
	{
		f *= 10;
		j++;
	}
	return (i + j);
}

int ft_float2int(double f, int *a, int *b, int precision)
{
	int	p_ent; 
	int	prec = 1;
	int	ret = 1;
	float p_dec;

	prec = ft_power(10, precision);
	p_ent = (int) f;
	p_dec = f - p_ent;	
	*a = p_ent;
	*b = (int)(p_dec * prec);
//	ft_putnbr((int)*b);
//	ft_putnbr((int)(p_dec * prec));
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



void ft_putfloat(double f, int precision)
{
	int reste = 0;
	int zero = 0;
	int b, a;
	ft_putnbr((long long)f);
	if (precision)
		ft_putchar('.');
	if (precision == -1)
		precision = 6;
	if(precision >= 6)
	{
		reste = precision - 6;
		precision = 6;
	}
	zero = ft_float2int(f, &a, &b, precision);
//	ft_putnbr(zero);
//	ft_putendl("is zeros");
	ft_putc_times('0', zero);
//	ft_putendl("is the 0s");
	ft_putnbr(b);
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

int main (void)
{
//	ft_putnbr(ft_float_len(123.0));
//	printf("\n[%lf]\n", 123456.0);
//	ft_putfloat(123456, -1);
//	printf("\n[%f]\n", 123.10);
//	ft_putfloat(123.10, -1);
	printf("\n[%f]\n", 123.0123);
	ft_putfloat(123.0123, -1);
//	printf("\n[%.0f]\n", 123.0123);
//	ft_putfloat(123.0123, 0);
	printf("\n\n[%.12f]\n", 123.0123);
	ft_putfloat(123.0123, 12);
	printf("\n[%f]\n", 123.00123);
	ft_putfloat(123.00123, -1);
	printf("\n[%f]\n", 123.000123);
	ft_putfloat(123.000123, -1);
	printf("\n[%.2f]\n", 123.0153);
	ft_putfloat(123.0153, 2);
	printf("\n[%.2f]\n", 123.000123);
	ft_putfloat(123.000123, 2);
	printf("\n[% .f]\n", 12.0);
	ft_putfloat(123.000123, 2);
	printf("\n[% +f]\n", 12.0);
	ft_putfloat(123.000123, 2);
	return (0);
}