/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 10:06:30 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_or(t_process *proc, t_data *d)
{
	t_args	*args;
	int		idx;

	(void)d;
	args = &proc->args;
	if (args->type[0] == REG_CODE)
		args->values[0] = proc->reg[args->values[0] - 1];
	else if (args->type[0] == IND_CODE)
	{
		idx = proc->start_pc + (args->values[0] % IDX_MOD);
		args->values[0] = get_int32_at_idx(d, idx);
	}
	if (args->type[1] == REG_CODE)
		args->values[1] = proc->reg[args->values[1] - 1];
	else if (args->type[1] == IND_CODE)
	{
		idx = proc->start_pc + (args->values[1] % IDX_MOD);
		args->values[1] = get_int32_at_idx(d, idx);
	}
	proc->reg[args->values[2] - 1] = args->values[0] | args->values[1];
	proc->carry = (proc->reg[args->values[2] - 1] == 0) ? 1 : 0;
}
