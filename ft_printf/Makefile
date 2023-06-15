SRCS = ft_printf.c ft_printf_hex.c ft_printf_nbr.c ft_printf_ptr.c ft_printf_un.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fcclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
