/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/09/30 14:22:33 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_st(t_process *proc, t_data *d)
{
	t_args	*args;
	int		value;
	int		idx;

	args = &proc->args;
	value = proc->reg[args->values[0] - 1];
	if (args->type[1] == REG_CODE)
		proc->reg[args->values[1] - 1] = value;
	else
	{
		idx = proc->start_pc + (args->values[1] % IDX_MOD);
		put_int32_at_idx(d, idx, value);
	}
	proc->carry = (!value) ? 1 : 0;
}
