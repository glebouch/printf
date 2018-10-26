/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/05/18 15:37:41 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
** %[specifier] == d, i, o, u, x, X, c, s, C, S, p, D, O, U;
**
*/



void	ft_str(t_stringinfo *t)
{
	t->string = va_arg(t->ap, wchar_t *);
	while(*t->string++ != '\0')
	{
		ft_putstr((char*)t->string);
	}
}

int	ft_char(t_stringinfo *t)
{
//	wchar_t ch;
	if (t->conversion == 3 || *t->str == 'C')
		t->ch = (wchar_t)va_arg(t->ap, int);
	else if (*t->str == 'c')
		t->ch = (char)va_arg(t->ap, int);
	return (4);
}

void ft_parse_specifier(t_stringinfo *t)
{
	int i;
//	ft_putstr("tototo\n");
	if (ft_strchr("Ddi", *t->str))
		ft_signed(t);
	else if (ft_strchr("oOuUxXp", *t->str))
		ft_unsigned(t);
	else if (*t->str == 's' || *t->str == 'S')
		ft_str(t);
	else if (*t->str == 'c' || *t->str == 'C')
		i = ft_char(t);
}

//OUp -> ne peut pas etre converti


//ouxX -> peut etre converti
/*
int		ft_error_length_specifier(t_stringinfo *t, char current, va_list ap)
{
	;
}

int		ft_specifier(t_stringinfo *t, char current)
{
	if(current == 'd' || current == 'i' || current == 'D')
		t->specifier = S_DECIMAL;
	else if(current == 'o' || current == 'O')
		t->specifier = U_OCTAL;
	else if(current == 'u' || current == 'U')
		t->specifier = U_DECIMAL;
	else if(current == 'x' || current == 'X')
		t->specifier = U_HEXA;
	else if(current == 'c' || current == 'C')
		t->specifier = CHAR;
	else if(current == 's' || current == 'S')
		t->specifier = STRING;
	else if(current == 'p')
		t->specifier = POINTER;
	else
		t->specifier = DEFAULT;
	return (OKAY);
}

int		ft_parse_specifier(t_stringinfo *t, va_list ap)
{
	char current;

	current = ft_current_char(t);
	ft_specifier(current)
	if(t->specifier == DEFAULT)
		return(OKAY);
	if(current == 'D' || current == 'O' || current == 'U' || 
		current == 'C' || current == 'S')
	{
		if (t->length != DEFAULT)
			ft_error_length_specifier(t, current, ap);
		t->length = L;
	}
	t->n_char++;
	return (OKAY);
}*/
