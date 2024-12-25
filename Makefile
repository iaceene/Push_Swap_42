BONUS_SRC = ./bonus/additional_func_bonus.c \
			./bonus/ft_atol_bonus.c \
			./bonus/instructions_utiles_bonus.c \
			./bonus/checker_bonus.c \
			./bonus/ft_splite_bonus.c \
			./bonus/get_next_line_utils_bonus.c \
			./bonus/main_bonus.c \
			./bonus/stack_a_bonus.c \
			./bonus/clear_list_bonus.c \
			./bonus/get_next_line_bonus.c \
			./bonus/instructions_bonus.c \
			./bonus/main_utiles_bonus.c \
			./bonus/stack_a_utiles_bonus.c \
			./bonus/checker_bonus.c

SRC = ./src/additional_func.c \
		./src/ft_atol.c \
		./src/instructions.c \
		./src/main.c \
		./src/push_swap.c \
		./src/stack_a.c \
		./src/clear_list.c \
		./src/ft_splite.c \
		./src/instructions_utiles.c \
		./src/main_utiles.c \
		./src/stack_a_utiles.c \
		./src/push_swap_utiles.c \
		./src/sort_above.c

BONUS_INCLUD = ./bonus/push_swap_bonus.h ./bonus/get_next_line_bonus.h
BONUS_NAME = checker
BONUS_OBJ = $(BONUS_SRC:.c=.o)

INCLUD = ./src/push_swap.h
NAME = push_swap
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUD)
	cc $(CFLAGS) -c $< -o $@

$(BONUS_NAME) : $(BONUS_OBJ)
	cc $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

$(BONUS_OBJ): %.o: %.c $(BONUS_INCLUD)
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(BONUS_NAME) $(NAME)

re : fclean all
