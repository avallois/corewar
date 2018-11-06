/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:40:12 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 09:41:27 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_args_values(t_data *d, t_process *proc, t_op *op, char *area)
{
	int		i;

	i = -1;
	while (++i < op->nb_args)
	{
		if (proc->args.type[i] == REG_CODE)
		{
			if (!(valide_idx_reg(area[proc->pc])))
				return (0);
			proc->args.values[i] = area[proc->pc];
			proc->pc = ++proc->pc % MEM_SIZE;
		}
		else if (proc->args.type[i] == IND_CODE ||
				(proc->args.type[i] == DIR_CODE && op->dir_is_2_bytes))
		{
			proc->args.values[i] = get_int16_at_idx(d, proc->pc);
			proc->pc = (2 + proc->pc) % MEM_SIZE;
		}
		else
		{
			proc->args.values[i] = get_int32_at_idx(d, proc->pc);
			proc->pc = (4 + proc->pc) % MEM_SIZE;
		}
	}
	return (1);
}

static int	type_arg(char arg_code)
{
	if (arg_code == IND_CODE)
		return (T_IND);
	else if (arg_code == DIR_CODE)
		return (T_DIR);
	else if (arg_code == REG_CODE)
		return (T_REG);
	else
		return (0);
}

static int	check_args_type(char ocp, t_op *op, t_process *proc)
{
	int		i;
	int		offset;
	char	arg_code;

	offset = 6;
	i = 0;
	while (i < op->nb_args)
	{
		arg_code = (ocp >> offset) & MASK_2_BITS;
		if (!(op->arg_types[i] & type_arg(arg_code)))
			return (FALSE);
		proc->args.type[i] = arg_code;
		offset -= 2;
		i++;
	}
	proc->pc = ++proc->pc % MEM_SIZE;
	return (TRUE);
}

int			handle_arguments(t_data *d, t_process *proc, t_op *op)
{
	char	*area;

	area = d->game_area;
	proc->pc = (proc->pc + OPCODE_BYTE) % MEM_SIZE;
	if (check_args_type(area[proc->pc], op, proc))
	{
		if (!(get_args_values(d, proc, op, area)))
			return (KILL);
	}
	else
		return (FAIL);
	return (SUCCESS);
}
