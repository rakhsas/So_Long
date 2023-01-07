NAME = so_long.a

SRC = 	get_next_line.c
GCC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

RM = rm -f

LIB = ar -rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@ $(LIB) $(NAME) $(OBJS)
	cd ./libft && make
	cd ./printf && make
clean :
	$(RM) $(OBJS)
	cd ./libft && make clean
	cd ./printf && make clean

fclean : clean
			$(RM) $(NAME)
			cd ./libft && make fclean
			cd ./printf && make fclean
re : fclean all
