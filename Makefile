# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glebouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 11:44:49 by glebouch          #+#    #+#              #
#    Updated: 2018/04/18 21:49:19 by glebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = test.c ft_parse_flags.c ft_parse_specifier.c ft_line.c unsigned.c signed.c char.c string.c float.c pointeur.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a 

INCLUDES = printf.h

CFLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) : $(OBJ) mlib
	libtool -static -o $@ $(LIB) $(OBJ)
#	ar rc $(NAME) $(OBJ) $(LIB)

mlib :
	@make -C ./libft/

%.o : %.c
	gcc -c $< -I $(INCLUDES)

clean :
	@make clean -C ./libft/
	
fclean :
	@make fclean -C ./libft/
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.o

re : fclean	all
