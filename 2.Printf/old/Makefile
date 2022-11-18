SRCS	= ${wildcard *.c}

OBJS 	= ${SRCS:.c=.o}

CC 		=gcc 

CFLAGS	= -Wall -Werror -Wextra 

NAME	= libftpintf.a

all:	${OBJS}
		ar -rsc ${NAME} ${OBJS}
		
clean:	
		rm -f ${SRCS}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

.PHONY: all clean fclean re bonus