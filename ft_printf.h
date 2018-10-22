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



/*typedef enum 	e_flags
{
	PLUS, MINUS, HASHTAG, SPACE, ZERO
}				t_flags;

typedef	enum	e_length
{
	DEFAULT, H, HH, J, L, LL, Z
}				t_length;

typedef enum	e_specifier
{
	S_DECIMAL, U_DECIMAL, U_HEXA, U_OCTAL, CHAR, STRING, POINTER, DEFAULT
}				t_specifier;
*/
typedef struct s_stringinfo
{
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
	wchar_t		*string;
	wchar_t		ch;
	va_list		ap;


}				t_stringinfo;

char *ft_strndup (const char *line, size_t i);
void	ft_parse_flags(t_stringinfo *t);
void	ft_parse_specifier(t_stringinfo *t);
void	ft_unsigned2(t_stringinfo *t);

/*
typedef struct	s_s
{
	size_t width;
	size_t precision;

	t_specifier specifier;
	t_length length;
	t_width width;
	t_flags flags;
	char *line;
}				t_s;
*/
#endif
