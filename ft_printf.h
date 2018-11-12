/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:27:37 by glebouch          #+#    #+#             */
/*   Updated: 2018/05/09 15:27:39 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/includes/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>

# define ERROR 0;
# define OKAY 1;
# define U_INT
# define S_INT
# define U_LONG_INT
# define S_LONT_INT
# define U_O
# define CHAR
# define STRING
# define POINTER 

typedef struct s_stringinfo
{
	int			ret;
	char		*line;
	int			conversion;
	int			space;
	int			zeros;
	int			aligne_g;
	int			sign;
	int			precision;
	int			prefixe;
	int			sizemin;
	int			len;
	char		*str;
	intmax_t	nbr;
	uintmax_t	unbr;
	char		*string;
	wchar_t		ch;
	va_list		ap;
}				t_stringinfo;

char		*ft_strndup (const char *line, size_t i);
void		ft_parse_flags(t_stringinfo *t);
void		ft_parse_specifier(t_stringinfo *t);
void		ft_unsigned(t_stringinfo *t);
void		ft_signed(t_stringinfo *t);
void		ft_char(t_stringinfo *t);
void		ft_str(t_stringinfo *t);
void		ft_init(t_stringinfo *t);
int			ft_size(uintmax_t n);
void		ft_putnbr_base(uintmax_t n, int base, int maj, int neg);
int			ft_size_base(uintmax_t n, int base);
void		ft_putchar_unicode(wchar_t caract, int oct);
int 		ft_octet(wchar_t caract);
int 		ft_oct_print(t_stringinfo *t, int nb_l_print);


#endif
