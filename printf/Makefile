# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 13:44:45 by rakhsas           #+#    #+#              #
#    Updated: 2023/01/07 13:14:19 by rakhsas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DIR = src

DIR_UTILS = utils

SRC = 	$(DIR)/ft_print_hex.c		\
		$(DIR)/ft_print_unsigned.c	\
		$(DIR)/ft_printf.c			\
		$(DIR)/ft_printf_utils.c	\
		$(DIR)/ft_print_ptr.c		\
		$(DIR_UTILS)/ft_itoa.c		\
		$(DIR_UTILS)/ft_putchar.c	\
		$(DIR_UTILS)/ft_putstr.c	\
		$(DIR_UTILS)/ft_strlen.c
GCC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

RM = rm -f

LIB = ar -rcs

all : $(NAME)

$(NAME) : $(OBJS)
	$(LIB) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)

re : fclean all
