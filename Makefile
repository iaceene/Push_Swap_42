BONUS_SRC=./bonus/additional_func_bonus.c \
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
			./bonus/stack_a_utiles_bonus.c
		
BONUS_INCLUD = ./bonus/push_swap_bonus.h ./bonus/push_swap_bonus.h
BONUS_NAME = checker
BONUS_OBJ = $(BONUS_SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ)
	cc $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c $(BONUS_INCLUD)
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(BONUS_OBJ)

fclean : clean
	rm -f $(BONUS_NAME)

re : fclean all