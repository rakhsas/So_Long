NAME = so_long
DIR = libft
DIR1 = printf/src
DIR_UTILS = printf/utils
SRC =	get_next_line.c checker.c helper.c think.c len.c positionp.c main.c\
		$(DIR)/ft_isalnum.c $(DIR)/ft_isalpha.c $(DIR)/ft_isdigit.c $(DIR)/ft_isprint.c $(DIR)/ft_memchr.c $(DIR)/ft_memcmp.c \
		$(DIR)/ft_memmove.c $(DIR)/ft_strlen.c $(DIR)/ft_memset.c $(DIR)/ft_isascii.c $(DIR)/ft_bzero.c $(DIR)/ft_memcpy.c \
		$(DIR)/ft_toupper.c $(DIR)/ft_tolower.c $(DIR)/ft_strchr.c $(DIR)/ft_strrchr.c $(DIR)/ft_strncmp.c $(DIR)/ft_strlcpy.c \
		$(DIR)/ft_strlcat.c $(DIR)/ft_strnstr.c $(DIR)/ft_atoi.c $(DIR)/ft_calloc.c $(DIR)/ft_strdup.c $(DIR)/ft_substr.c \
		$(DIR)/ft_strjoin.c $(DIR)/ft_strtrim.c $(DIR)/ft_split.c $(DIR)/ft_itoa.c $(DIR)/ft_strmapi.c $(DIR)/ft_striteri.c \
		$(DIR)/ft_putchar_fd.c $(DIR)/ft_putstr_fd.c $(DIR)/ft_putendl_fd.c $(DIR)/ft_putnbr_fd.c $(DIR)/ft_lstnew.c \
		$(DIR)/ft_lstadd_front.c $(DIR)/ft_lstsize.c $(DIR)/ft_lstlast.c $(DIR)/ft_lstadd_back.c $(DIR)/ft_lstdelone.c \
		$(DIR)/ft_lstclear.c $(DIR)/ft_lstiter.c $(DIR1)/ft_print_hex.c  $(DIR1)/ft_print_unsigned.c $(DIR1)/ft_printf.c \
		$(DIR1)/ft_printf_utils.c $(DIR1)/ft_print_ptr.c $(DIR_UTILS)/ft_itoa.c $(DIR_UTILS)/ft_putchar.c \
		$(DIR_UTILS)/ft_putstr.c $(DIR_UTILS)/ft_strlen.c

GCC = gcc

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
