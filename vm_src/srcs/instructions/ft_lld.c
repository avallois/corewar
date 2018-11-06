/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/09/24 14:42:07 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lld(t_process *proc, t_data *d)
{
	t_args	*args;
	int		idx;

	args = &proc->args;
	if (args->type[0] == IND_CODE)
	{
		idx = proc->start_pc + (args->values[0]);
		args->values[0] = get_int32_at_idx(d, idx);
	}
	proc->reg[proc->args.values[1] - 1] = proc->args.values[0];
	proc->carry = (proc->args.values[0] == 0);
}
