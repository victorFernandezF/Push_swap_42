# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:38:55 by victofer          #+#    #+#              #
#    Updated: 2023/01/30 12:25:05 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
NAME		:= push_swap.out

LIBFT_PATH	:= ./libft/ 
LIBFT_LIB	:= $(LIBFT_PATH)libft.a

SRC			:=  src/main.c \
				src/init_stack_data.c \
				input_handler/args_handler.c \
				checks_files/ckecks.c \
				error_management/errors.c \
				array_management/array_moves_1.c \
				array_management/array_moves_2.c \
				instructions/instructions_1.c \
				instructions/instructions_2.c \
				instructions/instructions_3.c \
				sorting/sorting_1.c \
				sorting/sorting_2.c \
				sorting/sorting_aux.c \
				sorting/sorting_aux_2.c \
				testing_files_to_delete/leaks_and_print_stacks.c

OBJECTS		:= $(SRC:.c=.o)

#COLORS
G = \033[0;32m
R = \033[0;31m
B = \033[0;34m
Y = \033[0;93m
M = \033[0;95m
E = \033[0m
#E COLORSmakecd 

all: nice_text makelibs $(NAME)

test:  $(NAME)

nice_text:
	@echo "$(Y)"
	@echo "PPPPPP  UU   UU  SSSSS  HH   HH          SSSSS  WW      WW   AAA   PPPPPP "
	@echo "PP   PP UU   UU SS      HH   HH         SS      WW      WW  AAAAA  PP   PP "
	@echo "PPPPPP  UU   UU  SSSSS  HHHHHHH          SSSSS  WW   W  WW AA   AA PPPPPP  "
	@echo "PP      UU   UU      SS HH   HH              SS  WW WWW WW AAAAAAA PP      "
	@echo "PP       UUUUU   SSSSS  HH   HH _______  SSSSS    WW   WW  AA   AA PP "



	
	@echo "$(E)"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -C $(SRC)

makelibs:
	@echo ""
	@echo "$(Y)0------ COMPILING LIBS -------0$(E)"
	@make -C $(LIBFT_PATH) all
	@echo "$(Y)|       $(G)Libft compiled 😀     $(Y)|"
	@echo "$(Y)0-----------------------------0 $(E)"
	@echo "$(E)"

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) libft/libft.a -o push_swap 
	@echo "   $(Y)0-----------------------0"
	@echo "   $(Y)|$(G)  push_swap Created 😁$(Y) |"
	@echo "   $(Y)0-----------------------0"
	@echo "$(E)"

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJECTS)
	@echo ""
	@echo "$(Y)0------------------------0"
	@echo "$(Y)|$(M)  Everything cleaned 👍$(Y) |"
	@echo "$(Y)0------------------------0"
	@echo "$(E)"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@rm -rf push_swap
	@rm -rf a.out

re: fclean all

.SILENT: $(OBJS)
.PHONY: clean fclean all re