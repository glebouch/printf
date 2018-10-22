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

NAME = exe

SRC = test.c ft_parse_flags.c ft_parse_specifier.c ft_line.c

OBJ = $(SRC:.c=.o)

LIB = -L ./libft/ -lft

INCLUDES = printf.h

CFLAGS = -Wall -Wextra -Werror -g3

all : mlib $(NAME)

mlib :
	@make -C ./libft/

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $^ $(LIB)

%.o : %.c
	gcc -c $< -I $(INCLUDES)

clean :
	@make clean -C ./libft/
	@/bin/rm -f *.o
	
fclean : clean
	@make fclean -C ./libft/
	@/bin/rm -f $(NAME)

re : fclean	all
