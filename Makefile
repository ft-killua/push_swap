CC=cc
FLAGS= -Wall -Werror -Wextra
RM=rm -rf

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

FILES= ft_assist_func_00.c \
ft_assist_func_01.c \
ft_checker.c \
ft_init.c \
ft_one_five_handred.c \
ft_pa_pb.c \
ft_ra_rb.c \
ft_rra_rrb_rrr.c \
ft_sa_sb_ss.c \
main.c \
push_swap.c \
main_utils.c \
ft_split.c \

BFILES = checker_bonus.c \
ft_assist_func_00.c \
ft_assist_func_01.c \
ft_checker.c \
ft_init.c \
ft_one_five_handred.c \
ft_pa_pb.c \
ft_ra_rb.c \
ft_rra_rrb_rrr.c \
ft_sa_sb_ss.c \
push_swap.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
ft_split.c \

OBJ=$(FILES:.c=.o)
BOBJ=$(BFILES:.c=.o)
NAME = push_swap
BONUS = checker

$(NAME):$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"

$(BONUS):$(BOBJ)
	@$(CC) $(FLAGS) $(BOBJ) -o $(BONUS)
	@echo "$(GREEN)█████████████████████ Checker is created  ██████████████████████$(RESET)"
%.o:%.c
	@echo "$(BLUE)██████████████████████     Compiling     ███████████████████████$(RESET)"
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME) 
bonus: $(BONUS)

clean:
	@echo "$(YELLOW)████████████████████  Object files cleaned  ████████████████████$(RESET)"
	@$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@echo "$(RED)████████████████████   Push_Swap cleaned    ████████████████████$(RESET)"
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re