NAME		=	philosophers

HEADER		=	philo.h

SRC			=	main.c life_cycle.c	get_time.c ft_atoi.c creating.c

OBJ			=	$(SRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror

%.o: %.c	$(HEADER)
			gcc $(FLAGS) -o $@ -c $< -I $(HEADER) -o $(<:.c=.o)

all:		$(NAME)
			@echo "Make is done"
			@say	"I am ready, like a fucken slave"

$(NAME):	$(OBJ) $(HEADER)
			gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f *.o
		@echo "All cleaned"
		@say	"All cleaned"

fclean:	clean
		rm -f $(NAME)
			
re:		fclean all

.PHONY:	all clean fclean re
		@say		"PHONY like a Pony"

