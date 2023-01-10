FILES =	ft_atoi.c ft_swap.c main.c

OBJS = ${FILES:.c=.o}
DEPS = ${FILES:.c=.d}
LIB = push_swap
CC = gcc

INCLUDE = -I ./
FLAGS = -Wall -Werror -Wextra

%.o: %.c fdf.h
			${CC} -I. ${FLAGS} -MMD -c $< -o ${<:.c=.o}

all: 	${OBJS}
		${CC} -o ${LIB} ${OBJS} ${INCLUDE} ${FLAGS}

clean:	
		rm -f ${OBJS}
		rm -rf *.d

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

-include ${DEPS}

.PHONY: all clean fclean re