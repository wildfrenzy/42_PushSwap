# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 15:53:14 by nmaliare          #+#    #+#              #
#    Updated: 2023/01/31 18:15:49 by nmaliare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

HEADER = push_swap.h

SRC = main.c lists.c rotate_swap.c sort.c a_to_b.c b_to_a.c rules.c \
	sort_helpers.c push_rules.c err.c

# Libft
LIBFT =  $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
LIBFT_FLAGS =  -lft -L $(LIBFT_DIR)

HEADER_FLAGS = -I $(LIBFT_DIR)

# COLORS
NOC         = \033[0m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(LIBFT) $(OBJ) $(HEADER)
	@cc $(FLAGS) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)
	@printf "$(GREEN)$(NAME) successfully compiled !$(NOC)\n"

$(OBJ): %.o:%.c $(HEADER)
	@cc $(FLAGS) -c $< -o $@ $(HEADER_FLAGS)
	@printf "$(GREEN)[\342\234\205] $(notdir $@)\n";

$(LIBFT):
	@printf "$(BLUE)Compiling libft files: $(NOC)"
	@make -C $(LIBFT_DIR)
	@printf "$(GREEN)[\342\234\205]\n"

clean:
	@if [ "$(wildcard $(addprefix ./, $(OBJ)))" ]; then\
		printf "$(BLUE)Cleaning $(NAME) files: $(YELLOW)$(OBJ)$(NOC) $(GREEN) [ \342\234\205 ] $(NOC)\n";\
		/bin/rm -f $(OBJ);\
	else\
		printf "$(YELLOW)There's no object files in $(NAME) \360\237\230\261$(NOC)\n";\
	fi

fclean: clean
	@if [ "$(wildcard $(addprefix ./, $(NAME)))" ]; then\
		printf "$(BLUE)Cleaning $(NAME): $(YELLOW)$(NAME) $(GREEN) [ \342\234\205 ]\n$(NOC)";\
		/bin/rm -f $(NAME);\
	else\
		printf "$(YELLOW)There's no $(GREEN)$(NAME) $(YELLOW)file here \360\237\230\261\n$(NOC)";\
	fi
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:	all clean fclean re

# https://apps.timwhitlock.info/emoji/tables/unicode	
# printf "\U1F631" | od -b
# printf '\360\237\230\261\***\n' 