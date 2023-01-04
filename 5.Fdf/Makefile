FILES =	ft_pc_id.c ft_pc_p.c ft_pc_u.c ft_pc_x.c ft_printf.c

OBJS = ${FILES:.c=.o}

LIB = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

all: 	${LIB}

clean:	
		rm -f ${OBJS}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

macos: 

.PHONY: all clean fclean re