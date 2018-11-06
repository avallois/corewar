/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 10:06:06 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_sti(t_process *proc, t_data *d)
{
	t_args	*args;
	int		value;
	int		idx;

	args = &proc->args;
	value = proc->reg[args->values[0] - 1];
	if (args->type[1] == REG_CODE)
		args->values[1] = proc->reg[args->values[1] - 1];
	else if (args->type[1] == IND_CODE)
	{
		idx = proc->start_pc + (args->values[1] % IDX_MOD);
		args->values[1] = get_int32_at_idx(d, idx);
	}
	if (args->type[2] == REG_CODE)
		args->values[2] = proc->reg[args->values[2] - 1];
	idx = proc->start_pc + (args->values[1] + args->values[2]) % IDX_MOD;
	put_int32_at_idx(d, idx, value);
}
