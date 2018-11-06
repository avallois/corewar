# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2018/10/01 16:20:41 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

# directories
SRC_DIR		= ./src
INC_DIR		= ./includes
OBJ_DIR		= ./obj
LIB_DIR		= ../../includes

# src / obj files

SRC = ft_printf.c \
	  parser.c \
	  parsing_tools.c \
	  converter.c \
	  conv_tools.c \
	  stocker_cs.c \
	  indent_tools.c \
	  indent_wchar.c \
	  itoa.c \
	  stocker_signed.c \
	  stocker_oux.c \
	  stocker_unsigned.c \
	  stocker_octal.c \
	  stocker_hexa.c \
	  stocker_pointer.c \
	  stocker_n.c \
	  stocker_wcs.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# libraries
L_FT		= $(LIB_DIR)
LIB_LNK		= -L $(L_FT) -lft
LIB_INC		= $(L_FT)/includes

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)
	@$(CC) $(CFLAGS)  -o $@ -c $< -I $(INC_DIR) -I $(LIB_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
