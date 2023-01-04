FILES =			ft_animation.c		ft_clean.c				ft_isdigit.c		ft_key_mouse_pt2.c	ft_map2.c \
ft_map_print.c	get_next_line.c		ft_atoi.c				ft_color_calcul.c	ft_itoa.c			ft_line.c \
ft_map.c		ft_monitoring.c		get_next_line_utils.c	ft_calloc.c			ft_color_map.c		ft_key_mouse.c \
ft_line_color.c	ft_map_calcul.c		ft_start.c

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