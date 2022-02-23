NAME 	 = libftprintf.a

SRCS	 = ft_init.c ft_libth_fn.c ft_p_flag.c \
			ft_print.c ft_print_c.c ft_printf.c \
			ft_print_s.c ft_print_digit.c ft_digit_plus.c \
			ft_digit_minus.c  ft_print_digit_u.c ft_print_x.c \
			ft_print_xx.c ft_print_p.c ft_print_pp.c \

OBJS	 = ${SRCS:.c=.o}

CC		 = gcc

RM		 = rm -f

INCLUDES = ft_printf.h

CFLAGS	 = -Wall -Wextra -Werror

%.o : %.c	$(INCLUDES)
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re