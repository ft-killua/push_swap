# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 19:16:44 by hidhmmou          #+#    #+#              #
#    Updated: 2022/11/15 20:55:47 by hidhmmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
FLAGS= -Wall -Werror -Wextra
RM=rm -rf

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

FILES= pa_pb.c \
rra_rrb_rrr.c \
sa_sb_ss_ra_rb_rr.c \
ft_check.c \
ft_ten.c \
utils_00.c \
ft_five.c \
ft_three.c \
utils_01.c \
ft_one_hundred.c \
main.c \
utils_main.c \

OBJDIR = objects
OBJ=$(FILES:.c=.o)
OBJFILES = $(OBJDIR)/$(OBJ)
NAME = push_swap
LIBFTDIR = ../libft
LIBFT.A = $(LIBFTDIR)/libft.a
	
$(NAME):$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT.A) -o $(NAME)
	@mv $(OBJ) $(OBJDIR)
	@echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"
%.o:%.c
	@echo "$(BLUE)██████████████████████     Compiling     ███████████████████████$(RESET)"
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re