# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 12:28:41 by iiliuk            #+#    #+#              #
#    Updated: 2023/03/15 12:27:07 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CFLAGS 	= 	-Wall -Wextra -Werror -g

SRC 	= 	src/main.c \
			src/init_stack.c \
			instructions/rr_instr.c \
			instructions/rrr_instr.c \
			instructions/s_and_p_instr.c \
			sort_files/start_sorting.c \
			sort_files/minisort.c \
			sort_files/big_sort.c \
			sort_files/find_max_min.c \
			sort_files/type_rotation.c \
			sort_files/calculate_cheaper_move.c \
			args_management/parse_args.c \
			args_management/split_args.c \
			utils/utilities.c \
			utils/utilities_2.c \
			utils/ft_special_atoi.c \
			free_and_errors/free_structs.c \
			free_and_errors/ft_errors.c \
			
OBJS		= $(SRC:.c=.o)

# T E X T   S T U F F
G = \033[0;92m
R = \033[0;31m
B = \033[0;96m	
Y = \033[0;33m
M = \033[0;95m
BOLD = \033[0;1m

E = \033[0m

LIBFT_PATH 	=  libft/
LIBFT		= -L./libft -lft
LIBFT		= libft/libft.a

all: nice_text makelibs $(NAME)

nice_text:
	@echo "$(B)"
	@echo "PPPPPP  UU   UU  SSSSS  HH   HH         SSSSS  WW     WW   AAA   PPPPPP "
	@echo "PP   PP UU   UU SS      HH   HH        SS      WW     WW  AAAAA  PP   PP "
	@echo "PPPPPP  UU   UU  SSSSS  HHHHHHH         SSSSS  WW  W  WW AA   AA PPPPPP "
	@echo "PP      UU   UU      SS HH   HH             SS WW WWW WW AAAAAAA PP      "
	@echo "PP       UUUUU   SSSSS  HH   HH _______ SSSSS   WW   WW  AA   AA PP "
	@echo "$(E)"

norminette:
	@echo ""
	@echo "$(Y) ---- N O R M I N E T T E ----$(E)"
	@sleep 1
	@echo "$(BOLD)"
	@norminette
	@echo "$(Y)------- $(G)EVERITHING OK$(Y) -------$(E)"
	
makelibs:
	@echo ""
	@echo "$(Y)0------ COMPILING LIBS -------0$(E)"
	@make -C $(LIBFT_PATH) all
	@echo "$(Y)|       $(G)Libft compiled        $(Y)|"
	@echo "$(Y)0-----------------------------0 $(E)"
	@echo "$(E)"

$(NAME): $(OBJS) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap 
	@echo "   $(Y)0-----------------------0"
	@echo "   $(Y)|$(G)  push_swap Created   $(Y) |"
	@echo "   $(Y)0-----------------------0"
	@echo "$(E)"

clean:
	@/bin/rm -f $(OBJS)
	@make -C ./libft clean

fclean: clean
	@echo ""
	@echo "$(Y)0------------------------0"
	@echo "$(Y)|$(M)  Everything cleaned   $(Y) |"
	@echo "$(Y)0------------------------0"
	@echo "$(E)"
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
.PHONY: all clean fclean re
.SILENT: $(OBJS)
