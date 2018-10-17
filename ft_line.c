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

void	ft_line_signed(t_stringinfo *t, int i)
{
	if((t->len = ft_strlen(ft_sizetoa(()nbr))) < t->sizemin)
		t->len = t->sizemin;
	t->line = ft_strnew(t->len);
	if 

}

void	ft_line_unsigned(t_stringinfo *t, int i)
{
	int i = 0;
	int len = 0;

	len = ft_size((size_t)nbr);
	if (t->space && t->precision > t->sizemin)
		t->len = 1;
//	if (t->precision > len)
//		t->precision -= len;
	t->precision = (t->precision > len) ? t->precision - len : 0;
//	if (t->sizemin > t->precision + len)
//		t->sizemin -= t->precision + len;
	t->sizemin = (t->sizemin > t->precision + len) ? t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
	if (!t->aligne_g)
	{
		while (t->sizemin-- > 0)
			ft_putchar(' ');
	}
	while (t->precision-- > 0)
		ft_putchar('0');



}
