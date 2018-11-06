# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 21:14:31 by cjumelin          #+#    #+#              #
#    Updated: 2018/10/01 14:33:22 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program
NAME = corewar

# directories
SRC_DIR		= ./srcs
INC_DIR		= ./includes
OBJ_DIR		= ./objs
LIB_DIR		= ./libft

SRC			=	main.c \
				parse_players.c \
				charge_players.c \
				run_processes.c \
				set_process_wait.c \
				handle_arguments.c \
				handle_arguments_helpers.c \
				handle_indirect.c \
				kill_player.c \
				dump_cycle.c \
				display.c \
		   		lst_processus_managing.c \
		   		instructions/ft_aff.c \
		   		instructions/ft_live.c \
		   		instructions/ft_add.c \
		   		instructions/ft_and.c \
		   		instructions/ft_fork.c \
		   		instructions/ft_ld.c \
		   		instructions/ft_ldi.c \
		   		instructions/ft_lfork.c \
		   		instructions/ft_lld.c \
		   		instructions/ft_lldi.c \
		   		instructions/ft_or.c \
		   		instructions/ft_st.c \
		   		instructions/ft_sti.c \
		   		instructions/ft_sub.c \
		   		instructions/ft_xor.c \
		   		instructions/ft_zjump.c \
				byte.c\
		   		error.c \
				free_vm.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# libraries
L_FT		= $(LIB_DIR)
LFT_LNK		= -L $(L_FT) -lft
LFT_INC		= $(L_FT)/includes
L_PF		= $(LIB_DIR)/srcs/printf
LPF_LNK		= -L $(L_PF) -lftprintf
LPF_INC		= $(L_PF)/includes

all: libft $(NAME)

libft:
	@$(MAKE) -C $(L_FT)

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $@/instructions

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR) -I $(LFT_INC) -I $(LPF_INC)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(MAKE) -C $(L_FT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LFT_LNK) $(LPF_LNK)
	@echo "\033[92m[OK]\033[0m"

clean:
	@$(MAKE) clean -C $(L_FT)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(L_FT)
	@rm -rf $(NAME)
	@rm -rf *.dSYM

re:
	@$(MAKE) fclean
	@$(MAKE) all
