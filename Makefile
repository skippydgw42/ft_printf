NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./includes

OBJS = ${SRCS:.c=.o}

HEADER = libftprintf.h

SRCS = ft_printf.c\

all :	${NAME}

%.o :		%.c ${HEADER}
	${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
	make -C ./libft
	ar -cr ${NAME} ${OBJS}

clean :
	/bin/rm -f ${OBJS} ${OBJS_BONUS}

fclean :	clean
	/bin/rm -f ${NAME}

re :		fclean all

.PHONY : all clean fclean re
