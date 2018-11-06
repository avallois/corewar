/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:28:27 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 09:28:55 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	handle_error_(int err_code)
{
	if (err_code == ERR_DIGIT)
		ft_putendl_fd("Wrong entry after '-n' flag (digit string is needed)",
					2);
	if (err_code == ERR_SAME_NBR)
		ft_putendl_fd("Try to define two player at the same number.", 2);
	if (err_code == ERR_PLAYR_NBR)
		ft_putendl_fd("Can't attribute a number between {-4, -1} to player"
					, 2);
	if (err_code == ERR_MAX_PLAYER)
		ft_putendl_fd("Too many players.", 2);
	if (err_code == ERR_HEADER)
		ft_putendl_fd("Player file not well formated", 2);
	if (err_code == ERR_PROG_SIZE)
		ft_putendl_fd("Program size is over CHAMP_MAX_SIZE or equals zero", 2);
	if (err_code == ERR_OP)
		ft_putendl_fd("Instruction code isn't referenced", 2);
	if (err_code == ERR_OCP)
		ft_putendl_fd("Bytecode for arguments instruction is illegale.. ", 2);
	if (err_code == DEBUG)
		ft_putendl_fd("DEBUG", 2);
}

void		handle_error(t_data *d, int err_code)
{
	if (err_code == ERR_MALLOC)
		ft_putendl_fd("Malloc error.", 2);
	if (err_code == ERR_NULL)
		ft_putendl_fd("Null error.", 2);
	if (err_code == ERR_OPEN)
		ft_putendl_fd("Open error.", 2);
	if (err_code == ERR_USAGE)
		ft_putendl_fd("./corewar [-dump nbr_cycles] [-ncurse] \
[[-n] champion1.cor] ...", 2);
	handle_error_(err_code);
	free_vm(d);
	exit(-1);
}
