/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 10:06:51 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_zjump(t_process *proc, t_data *d)
{
	int		idx;

	proc->pc = (proc->pc + OPCODE_BYTE) % MEM_SIZE;
	if (proc->carry == 1)
	{
		idx = get_int16_at_idx(d, proc->pc);
		proc->pc = (proc->start_pc + idx + MEM_SIZE) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + INT16_SIZE) % MEM_SIZE;
}
