# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhanda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 15:50:47 by selhanda          #+#    #+#              #
#    Updated: 2021/11/22 15:54:11 by selhanda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRC=ft_printf.c ft_printf_utils.c ft_itoa.c ft_printf_unsigned.c ft_print_ptr.c ft_print_hex.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean all
