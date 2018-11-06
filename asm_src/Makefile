# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2018/10/01 11:38:26 by cjumelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# programs
NAME		= asm

# directories
SRC_DIR		= ./src
INC_DIR		= ./includes
OBJ_DIR		= ./obj
LIB_DIR		= ./libft

# src / obj files
				#parse_name.c
				#parse_comment.c

SRC			=	main.c \
				init.c\
				check_file.c\
				parser.c\
				parser_helper.c\
				parse_header.c\
				parse_prog.c\
				parse_label.c\
				parse_op.c\
				parse_param.c\
				fill_param.c\
				fill_label.c\
				byte.c\
				treat_file.c\
				write_cor.c\
				free.c\
				op.c\
				handle_error.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# libraries
L_FT		= $(LIB_DIR)
LIB_LNK		= -L $(L_FT) -lft
LIB_INC		= $(L_FT)/includes

all: libft $(NAME)

libft:
	@$(MAKE) -C $(L_FT)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR) -I $(LIB_INC)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(MAKE) -C $(L_FT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB_LNK)
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
