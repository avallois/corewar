# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 12:16:13 by plamusse          #+#    #+#              #
#    Updated: 2018/09/17 13:37:54 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_ASM =		asm_src/asm
BIN_COREWAR =	vm_src/corewar

all: corewar asm

corewar:
		@echo "\033[34m\033[47mBuilding $@ :\033[0m"
		@make -C vm_src
		@cp $(BIN_COREWAR) .

asm:
		@echo "\033[34m\033[47mBuilding $@ :\033[0m"
		@make -C asm_src
		@cp $(BIN_ASM) .

clean:
		@echo "\033[33m$@\033[0m"
		@make clean -C vm_src
		@make clean -C asm_src

fclean:
		@echo "\033[33m$@\033[0m"
		@make fclean -C vm_src
		@make fclean -C asm_src
		@rm -f asm
		@rm -f corewar

re: fclean all

.PHONY: all clean fclean re corewar asm
