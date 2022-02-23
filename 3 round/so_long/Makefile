NAME		=	so_long

BONUS_NAME	=	so_long_bonus

SRC			=	so_long.c ft_split.c ft_strlen.c ft_itoa.c \
				protect.c write_map.c parsing.c checker_map.c \
				init.c read_map.c error.c game_over.c hot_keys.c

OBJ			=	$(SRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror

HEADER		=	so_long.h

FRAEMWORKS	=	-lmlx -framework OpenGL -framework AppKit

%.o: %.c $(HEADER)
		gcc $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(HEADER)
		gcc ${FLAGS} $(FRAEMWORKS) $(OBJ) -o $(NAME)

bonus 	: $(OBJ) $(HEADER)
		gcc ${FLAGS} $(FRAEMWORKS) $(OBJ) -o $(BONUS_NAME)

all:	$(NAME)

clean:
		rm -f *.o

fclean:	clean
		rm -f $(NAME) $(BONUS_NAME)
			
re:		fclean all

.PHONY:	all clean fclean re