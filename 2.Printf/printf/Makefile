SRCS	= ${wildcard *.c}

OBJS 	= ${SRCS:.c=.o}

CC 		=gcc 

CFLAGS	= -Wall -Werror -Wextra 

NAME	= libftpintf.a

all:	${OBJS}
		ar -rsc ${NAME} ${OBJS}
		

