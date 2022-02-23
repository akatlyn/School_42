NAME		=	push_swap

BONUS_NAME	=	checker

HEADER		=	push_swap.h

BONUS_HEAD	=	bonus/checker.h

SRC			=	push_swap.c				push_to_a.c			spin_a.c		spin_b.c \
				steps_counter.c 		swap_rr.c 			swap_rrr.c 		swap_ss.c \
				swaps_a.c 				swaps_b.c 			algorithm_for_three.c \
				algorithm_oversize.c 	best_choice.c 		check_index.c \
				error.c 				ft_atoi.c 			ft_list_clear.c \
				ft_split.c				get_index.c input.c list_lib.c

BONUS_SRCS	=	bonus/checker.c			bonus/get_next_line.c	bonus/errors.c \
				bonus/ft_atoi.c 		bonus/ft_list_clear.c	bonus/ft_split.c\
				bonus/get_index.c 		bonus/input.c 			bonus/list_lib.c \
				bonus/mimic.c			bonus/swap_rr.c 		bonus/swap_rrr.c \
				bonus/swap_ss.c			bonus/swaps_a.c			bonus/swaps_b.c \
				bonus/ft_strcmp.c 		bonus/final_checker.c

OBJ			=	$(SRC:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

FLAGS		=	-Wall -Wextra -Werror

%.o: %.c	$(HEADER)
			gcc $(FLAGS) -o $@ -c $< -I $(HEADER) -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			gcc $(FLAGS) $(OBJ) -o $(NAME)

bonus:		$(BONUS_OBJS) $(BONUS_HEAD)
			gcc $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
		rm -f *.o bonus/*.o

fclean:	clean
		rm -f $(NAME) $(BONUS_NAME)
			
re:		fclean all

.PHONY:	all clean fclean re