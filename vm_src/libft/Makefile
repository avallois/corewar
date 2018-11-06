# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 21:14:31 by cjumelin          #+#    #+#              #
#    Updated: 2018/10/01 16:19:46 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# directories
SRC_DIR		= ./srcs
INC_DIR		= ./includes
OBJ_DIR		= ./objs


SRC = ft_strndup.c \
	  	ft_abs.c\
		ft_add_str.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isdigit_str.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strtrim.c \
		ft_strsub.c \
		ft_strstr.c \
		ft_strsplit.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strnew.c \
		ft_strnequ.c \
		ft_strncpy.c \
		ft_strncmp.c \
		ft_strncat.c \
		ft_strmapi.c \
		ft_strmap.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strjoin.c \
		ft_striteri.c \
		ft_striter.c \
		ft_strequ.c \
		ft_strdup.c \
		ft_strdel.c \
		ft_strcpy.c \
		ft_strcmp.c \
		ft_strclr.c \
		ft_strchr.c \
		ft_strcat.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_putnbr_fd.c \
		ft_strjoin_free_s1.c \
		ft_putnbr.c \
		get_next_line.c \
		free_n_gnl.c \
		ft_p_ptab_cmp.c \
		ft_add_p_to_ptab.c \
		ft_str_tstr_cmp.c \
		ft_tstrcpy.c \
		hexdump.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make -C srcs/printf

clean:
	@rm -rf $(OBJ_DIR)
	@make -C srcs/printf clean

fclean: clean
	@rm -rf $(NAME)
	@make -C srcs/printf fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all
