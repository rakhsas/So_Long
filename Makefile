NAME = so_long
DIR = libft
DIR1 = printf/src
DIR_UTILS = printf/utils
SRC =	get_next_line.c checker.c helper.c think.c len.c positionp.c main.c

GCC = gcc

FLAG = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -fsanitize=address

OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	make -C ./printf
	cc $(FLAG) -o $(NAME) $(OBJS) ./libft/libft.a ./printf/libftprintf.a
clean :
	make clean -C ./libft
	make clean -C ./printf
	$(RM) $(OBJS)

fclean : clean
			make clean -C ./libft
			make clean -C ./printf
			$(RM) $(NAME)
re : fclean all
