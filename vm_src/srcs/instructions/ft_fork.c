/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 16:13:59 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_fork_wait(t_data *d, t_process *proc)
{
	proc->pc %= MEM_SIZE;
	if (d->game_area[proc->pc] <= 16 && d->game_area[proc->pc] >= 1)
		proc->wait = g_op_tab[d->game_area[proc->pc] - 1].nb_cycles + 1;
	else
		proc->wait = 1;
}

void		ft_fork(t_process *proc, t_data *d)
{
	t_process	*new;
	int			ind_adrs;
	int			i;

	proc->pc = (proc->pc + OPCODE_BYTE) % MEM_SIZE;
	if (!(new = (t_process *)malloc(sizeof(t_process))))
		handle_error(d, ERR_MALLOC);
	ft_bzero((void*)new, sizeof(t_process));
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = proc->reg[i];
	new->player_nbr = proc->player_nbr;
	new->carry = proc->carry;
	new->n = proc->n;
	new->p = proc;
	proc->n = new;
	new->n->p = new;
	ind_adrs = (proc->start_pc + get_int16_at_idx(d, proc->pc)) % IDX_MOD;
	new->pc = (ind_adrs + MEM_SIZE) % MEM_SIZE;
	proc->pc = (proc->pc + INT16_SIZE + MEM_SIZE) % MEM_SIZE;
	set_fork_wait(d, new);
	proc->live_current_period = 1;
	++d->run.nprocesses;
}
