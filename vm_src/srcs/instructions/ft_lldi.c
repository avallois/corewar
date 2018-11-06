/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/09/24 14:42:47 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lldi(t_process *proc, t_data *d)
{
	t_args	*args;
	int		value;
	int		idx;

	args = &proc->args;
	if (args->type[0] == REG_CODE)
		args->values[0] = proc->reg[args->values[0] - 1];
	else if (args->type[0] == IND_CODE)
	{
		idx = proc->start_pc + (args->values[0]);
		args->values[0] = get_int32_at_idx(d, idx);
	}
	if (args->type[1] == REG_CODE)
		args->values[1] = proc->reg[args->values[1] - 1];
	value = args->values[0] + args->values[1];
	idx = proc->start_pc + value;
	proc->reg[proc->args.values[2] - 1] = get_int32_at_idx(d, idx);
	proc->carry = (proc->reg[proc->args.values[2] - 1] == 0);
}
