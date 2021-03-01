CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_check_option.c ft_print_arg.c ft_print_arg2.c ft_printf.c ft_utils.c

OBJS = ${SRCS:.c=.o}

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
